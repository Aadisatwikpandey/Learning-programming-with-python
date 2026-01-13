//container with most water
//Question:
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1






//one approach, which is not feasible due to time limit constraint
int maxArea(int* height, int heightSize) {
    // int farr[heightSize];
    int length,breadth,result,least;
    int max=0;
    
    for(int i=0;i<heightSize;i++){
        for(int k=0;k<heightSize;k++){
            breadth=k-i;
            if(breadth<0){
                breadth=breadth*(-1);
            }
            if(height[i]<height[k]){
                result=breadth*height[i];
                if(result>max){
                    max=result;
                }

            }
            else{
                result=breadth*height[k];
                if(result>max){
                    max=result;
                }
            }
        }
    }
return max;
}

//Solved this with two pointer approach
int maxArea(int* height, int heightSize) {
    // int farr[heightSize];
    int length,result,least;
    int h1Count=0;
    int h2Count=heightSize-1;
    int max=0;
    int i=0;
    while(i<heightSize){
        int breadth = h2Count-h1Count;
        int h1=height[h1Count];
        int h2=height[h2Count];
        if(h1<h2){
            result=breadth*h1;
            if(result>max){
                max=result;
            }
            h1Count=h1Count+1;
            breadth=h2Count-h1Count;
        }          
        else{
            result=breadth*h2;
            if(result>max){
                max=result;
            }
            h2Count--;
            breadth=h2Count-h1Count;
        } 
        i++;
    }
return max;
}




//Visual representation:
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Max Area Visualization</title>
    <style>
        body {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            min-height: 100vh;
            margin: 0;
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
        }
        .container {
            background: white;
            padding: 30px;
            border-radius: 15px;
            box-shadow: 0 20px 60px rgba(0,0,0,0.3);
            max-width: 900px;
            width: 90%;
        }
        h2 {
            text-align: center;
            color: #333;
            margin-bottom: 20px;
        }
        .canvas-container {
            position: relative;
            background: #f8f9fa;
            border-radius: 10px;
            padding: 20px;
            margin: 20px 0;
        }
        canvas {
            border: 2px solid #ddd;
            border-radius: 8px;
            background: white;
            display: block;
            margin: 0 auto;
        }
        .controls {
            display: flex;
            gap: 10px;
            justify-content: center;
            margin: 20px 0;
            flex-wrap: wrap;
        }
        button {
            padding: 12px 24px;
            font-size: 16px;
            border: none;
            border-radius: 8px;
            cursor: pointer;
            background: #667eea;
            color: white;
            transition: all 0.3s;
            font-weight: 600;
        }
        button:hover {
            background: #5568d3;
            transform: translateY(-2px);
            box-shadow: 0 5px 15px rgba(102, 126, 234, 0.4);
        }
        button:disabled {
            background: #ccc;
            cursor: not-allowed;
            transform: none;
        }
        .info {
            background: #e3f2fd;
            padding: 15px;
            border-radius: 8px;
            margin: 15px 0;
            border-left: 4px solid #2196f3;
        }
        .info-grid {
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(150px, 1fr));
            gap: 10px;
            margin-top: 10px;
        }
        .info-item {
            background: white;
            padding: 10px;
            border-radius: 6px;
            text-align: center;
        }
        .info-label {
            font-size: 12px;
            color: #666;
            font-weight: 600;
            text-transform: uppercase;
        }
        .info-value {
            font-size: 20px;
            color: #333;
            font-weight: bold;
            margin-top: 5px;
        }
        .legend {
            display: flex;
            gap: 20px;
            justify-content: center;
            flex-wrap: wrap;
            margin: 15px 0;
        }
        .legend-item {
            display: flex;
            align-items: center;
            gap: 8px;
        }
        .legend-color {
            width: 20px;
            height: 20px;
            border-radius: 4px;
        }
    </style>
</head>
<body>
    <div class="container">
        <h2>Container With Most Water - Algorithm Visualization</h2>
        
        <div class="info">
            <div class="info-grid">
                <div class="info-item">
                    <div class="info-label">Left Pointer</div>
                    <div class="info-value" id="h1Val">-</div>
                </div>
                <div class="info-item">
                    <div class="info-label">Right Pointer</div>
                    <div class="info-value" id="h2Val">-</div>
                </div>
                <div class="info-item">
                    <div class="info-label">Width</div>
                    <div class="info-value" id="breadthVal">-</div>
                </div>
                <div class="info-item">
                    <div class="info-label">Current Area</div>
                    <div class="info-value" id="currentArea">-</div>
                </div>
                <div class="info-item">
                    <div class="info-label">Max Area</div>
                    <div class="info-value" id="maxArea">0</div>
                </div>
            </div>
        </div>

        <div class="legend">
            <div class="legend-item">
                <div class="legend-color" style="background: #4CAF50;"></div>
                <span>Left Pointer</span>
            </div>
            <div class="legend-item">
                <div class="legend-color" style="background: #f44336;"></div>
                <span>Right Pointer</span>
            </div>
            <div class="legend-item">
                <div class="legend-color" style="background: rgba(33, 150, 243, 0.3);"></div>
                <span>Water Area</span>
            </div>
        </div>

        <div class="canvas-container">
            <canvas id="canvas" width="800" height="400"></canvas>
        </div>

        <div class="controls">
            <button id="stepBtn">Step Through</button>
            <button id="runBtn">Run All</button>
            <button id="resetBtn">Reset</button>
        </div>

        <div class="info" style="background: #fff3e0; border-left-color: #ff9800;">
            <div style="margin-bottom: 10px; font-weight: 600; color: #333;">Enter Your Array</div>
            <input type="text" id="arrayInput" placeholder="e.g., 1,8,6,2,5,4,8,3,7" 
                style="width: 100%; padding: 10px; border: 2px solid #ddd; border-radius: 6px; font-size: 16px; box-sizing: border-box;">
            <button id="updateBtn" style="margin-top: 10px; width: 100%;">Update Array</button>
            <div style="margin-top: 10px; font-size: 14px; color: #666;">
                Enter comma-separated numbers (e.g., 1,8,6,2,5,4,8,3,7)
            </div>
        </div>
    </div>

    <script>
        const canvas = document.getElementById('canvas');
        const ctx = canvas.getContext('2d');
        
        // Sample heights array
        let heights = [1, 8, 6, 2, 5, 4, 8, 3, 7];
        
        let h1Count = 0;
        let h2Count = heights.length - 1;
        let maxArea = 0;
        let i = 0;
        let isRunning = false;
        let stepInterval;

        function drawVisualization() {
            ctx.clearRect(0, 0, canvas.width, canvas.height);
            
            // Calculate dynamic sizing
            const totalWidth = canvas.width - 100;
            const barWidth = Math.min(60, (totalWidth - (heights.length - 1) * 10) / heights.length);
            const gap = Math.min(20, (totalWidth - barWidth * heights.length) / (heights.length - 1));
            const startX = (canvas.width - (barWidth * heights.length + gap * (heights.length - 1))) / 2;
            const maxHeight = Math.max(...heights);
            const scale = 300 / maxHeight;

            // Draw bars
            heights.forEach((h, idx) => {
                const x = startX + idx * (barWidth + gap);
                const barHeight = h * scale;
                const y = canvas.height - 50 - barHeight;

                // Highlight selected bars
                if (idx === h1Count) {
                    ctx.fillStyle = '#4CAF50';
                } else if (idx === h2Count) {
                    ctx.fillStyle = '#f44336';
                } else {
                    ctx.fillStyle = '#ddd';
                }

                ctx.fillRect(x, y, barWidth, barHeight);
                ctx.strokeStyle = '#333';
                ctx.lineWidth = 2;
                ctx.strokeRect(x, y, barWidth, barHeight);

                // Draw height labels
                ctx.fillStyle = '#333';
                ctx.font = 'bold 14px Arial';
                ctx.textAlign = 'center';
                ctx.fillText(h, x + barWidth/2, canvas.height - 20);
            });

            // Draw water area if both pointers are valid
            if (h1Count <= h2Count) {
                const h1 = heights[h1Count];
                const h2 = heights[h2Count];
                const minHeight = Math.min(h1, h2);
                const waterHeight = minHeight * scale;
                
                const x1 = startX + h1Count * (barWidth + gap);
                const x2 = startX + h2Count * (barWidth + gap) + barWidth;
                const y = canvas.height - 50 - waterHeight;

                ctx.fillStyle = 'rgba(33, 150, 243, 0.3)';
                ctx.fillRect(x1, y, x2 - x1, waterHeight);
                ctx.strokeStyle = 'rgba(33, 150, 243, 0.8)';
                ctx.lineWidth = 2;
                ctx.strokeRect(x1, y, x2 - x1, waterHeight);
            }

            updateInfo();
        }

        function updateInfo() {
            if (h1Count <= h2Count) {
                const h1 = heights[h1Count];
                const h2 = heights[h2Count];
                const breadth = h2Count - h1Count;
                const currentArea = breadth * Math.min(h1, h2);

                document.getElementById('h1Val').textContent = `${h1} (index ${h1Count})`;
                document.getElementById('h2Val').textContent = `${h2} (index ${h2Count})`;
                document.getElementById('breadthVal').textContent = breadth;
                document.getElementById('currentArea').textContent = currentArea;
                document.getElementById('maxArea').textContent = maxArea;
            }
        }

        function step() {
            if (i >= heights.length || h1Count >= h2Count) {
                stop();
                return;
            }

            const breadth = h2Count - h1Count;
            const h1 = heights[h1Count];
            const h2 = heights[h2Count];
            
            let result;
            if (h1 < h2) {
                result = breadth * h1;
                if (result > maxArea) {
                    maxArea = result;
                }
                h1Count = h1Count + 1;
            } else {
                result = breadth * h2;
                if (result > maxArea) {
                    maxArea = result;
                }
                h2Count--;
            }
            
            i++;
            drawVisualization();
        }

        function reset() {
            stop();
            h1Count = 0;
            h2Count = heights.length - 1;
            maxArea = 0;
            i = 0;
            drawVisualization();
        }

        function runAll() {
            if (isRunning) return;
            isRunning = true;
            document.getElementById('runBtn').disabled = true;
            document.getElementById('stepBtn').disabled = true;
            
            stepInterval = setInterval(() => {
                if (h1Count >= h2Count) {
                    stop();
                } else {
                    step();
                }
            }, 800);
        }

        function stop() {
            isRunning = false;
            clearInterval(stepInterval);
            document.getElementById('runBtn').disabled = false;
            document.getElementById('stepBtn').disabled = false;
        }

        document.getElementById('stepBtn').addEventListener('click', step);
        document.getElementById('runBtn').addEventListener('click', runAll);
        document.getElementById('resetBtn').addEventListener('click', reset);
        
        document.getElementById('updateBtn').addEventListener('click', () => {
            const input = document.getElementById('arrayInput').value;
            const newHeights = input.split(',').map(s => parseInt(s.trim())).filter(n => !isNaN(n) && n > 0);
            
            if (newHeights.length < 2) {
                alert('Please enter at least 2 valid positive numbers separated by commas');
                return;
            }
            
            heights = newHeights;
            reset();
        });
        
        // Set initial input value
        document.getElementById('arrayInput').value = heights.join(',');

        // Initial draw
        drawVisualization();
    </script>
</body>
</html>