import { useState, useEffect } from 'react'
import "./index.css"
/**
 * @param {string} icon - Emoji icon to display (e.g., "🍌" for wet waste)
 * @param {string} title - Title of the trash can (e.g., "Wet Waste")
 * @param {string} type - Type of trash can ("wet" or "dry") - determines fill color
 * @param {number} originalDepth - Original empty depth of trash can in centimeters
 * @param {number} currentDepth - Current depth reading from ultrasonic sensor in cm
 * @param {function} onOriginalChange - Callback function when user changes original depth
 * @param {function} onCurrentChange - Callback function when user changes current depth
 */

const TrashCan = ({
    icon,
    title,
    type,
    originalDepth,
    currentDepth,
}) => {
    /**
    * @param {number} originalDepth
    * @param {number} currentDepth
    * @returns {number}
    */
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

        <div className="battery-container">
            <div className="battery-outline">
                <div
                    className={`battery-fill {type}-fill`}
                    style={{height: `${fill-percentage + 10}%`}}
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
            fetch("http:127.0.0.1:5000/api/data")
                .then(res => res.json())
                .then(json => {
                    setWetOriginalDepth(json.wetOriginalDepth)
                    setDryOriginalDepth(json.dryOriginalDepth)
                    setWetCurrentDepth(json.wetCurrentDepth)
                    setDryCurrentDepth(json.dryOriginalDepth)
                });
        };

        fetchData();

        const interval = setInterval(fetchData, 5000);

        return () => clearInterval(interval);
    }, []);

    return (
        <div className="app">
            <h1>Trash Monitor</h1>

            <div className="trash-cans-container">
                <TrashCan
                    icon="🍌"
                    title="Wet Waste"
                    type="wet"
                    originalDepth ={ wetOriginalDepth}
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