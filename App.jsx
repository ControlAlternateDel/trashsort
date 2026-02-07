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
    
   }
}