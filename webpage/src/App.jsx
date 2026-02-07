import { useState, useEffect } from 'react'
import "./index.css"

const TrashCan = ({
    icon,
    title,
    type,
    originalDepth,
    currentDepth,
}) => {
   const calculateFillPercentage = (originalDepth, currentDepth) => {
    if (originalDepth <= 0 ) return 0
    const filledDepth = originalDepth - currentDepth

    const percentage = (filledDepth/originalDepth) * 100

    return Math.max(0, Math.min(100, percentage))
   }

   const fillPercentage = calculateFillPercentage(originalDepth, currentDepth)

   return(
    <div className="trash-can-card">
        <div className="icon-container">
            <div className="icon">{icon}</div>
            <h2>{title}</h2>
        </div>
        <span className={`filler-text-${type}`}>Capacity:</span>
        <div className="battery-container">
            <div className="battery-outline">
                <div
                    className={`battery-fill ${type}-fill`}
                    style={{ height: `${fillPercentage + 10}%` }}
                >
                    <div className="wave-overlay"></div>
                    <span className="fill-percentage">{Math.round(fillPercentage)}%</span>
                </div>
            </div>
        </div>
    </div>
   )
}


function App() {
    const [wetOriginalDepth, setWetOriginalDepth] = useState(null)
    const [dryOriginalDepth, setDryOriginalDepth] = useState(null)

    const [wetCurrentDepth, setWetCurrentDepth] = useState(null)
    const [dryCurrentDepth, setDryCurrentDepth] = useState(null)

    useEffect(() => {
        const fetchData = () => {
            fetch("http://127.0.0.1:5000/api/data")
                .then(res => res.json())
                .then(json => {
                    setWetOriginalDepth(json.wetOriginalDepth)
                    setDryOriginalDepth(json.dryOriginalDepth)
                    setWetCurrentDepth(json.wetCurrentDepth)
                    setDryCurrentDepth(json.dryCurrentDepth)
                });
        };

        fetchData();

        const interval = setInterval(fetchData, 5000);

        return () => clearInterval(interval);
    }, []);

    return (
        <div className="app">
            <h1>Trash Monitor</h1> 
            <h2 style={{color: "#FFFFFF"}} className="amount-text">Amount of trash recycled: {(82*82*((wetCurrentDepth+dryCurrentDepth)/4))/1000}cm<sup>3</sup></h2>
            <div className="trash-cans-container">
                <TrashCan
                    icon="🍌"
                    title="Wet Waste"
                    type="wet"
                    originalDepth ={wetOriginalDepth}
                    currentDepth = {wetCurrentDepth}
                    onOriginalChange = {setWetOriginalDepth}
                    onCurrentChange = {setWetCurrentDepth}
                />

                <TrashCan
                    icon="🥤"
                    title="Dry Waste"
                    type="dry"
                    originalDepth = {dryOriginalDepth}
                    currentDepth = {dryCurrentDepth}
                    onOriginalChange = {setDryOriginalDepth}
                    onCurrentChange = {setDryCurrentDepth}
                />
            </div>
        </div>
    )
}

export default App