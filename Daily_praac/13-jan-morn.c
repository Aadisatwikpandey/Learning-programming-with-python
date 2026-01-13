//median of two sorted array

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int s= nums1Size+nums2Size;
    int farr[s];
    int farrSize = nums1Size+nums2Size;
    int temp,mid;
    float result;
    mid = s/2;

    //add the array 1 into farr array
    for(int l=0;l<nums1Size;l++){
        farr[l]=nums1[l];
    }
    //add the array 2 into the farr array
    for(int j=0;j<nums2Size;j++){
        farr[j+nums1Size]=nums2[j];
    }

    //Sorting the new array
    for (int i=0;i<s;i++){
        for(int k=0;k<s;k++){
            if(farr[k]>farr[i]){
                temp=farr[k];
                farr[k]=farr[i];
                farr[i]=temp;
            }
        }
    }
    //if even
    if (farrSize%2==0){
        int sum=farr[mid]+farr[mid-1];
        result = sum/2.0;
    }
    else{
        result=farr[mid];
    }
return result;
}



//visual representation of the code in HTML and CSS and JS

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Median Finder Visualization</title>
    <style>
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }
        
        body {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
            min-height: 100vh;
            padding: 20px;
        }
        
        .container {
            max-width: 1000px;
            margin: 0 auto;
            background: white;
            border-radius: 20px;
            padding: 40px;
            box-shadow: 0 20px 60px rgba(0,0,0,0.3);
        }
        
        h1 {
            color: #667eea;
            text-align: center;
            margin-bottom: 30px;
            font-size: 2em;
        }
        
        .input-section {
            margin-bottom: 30px;
            padding: 20px;
            background: #f8f9fa;
            border-radius: 10px;
        }
        
        .input-group {
            margin-bottom: 15px;
        }
        
        label {
            display: block;
            margin-bottom: 5px;
            font-weight: 600;
            color: #333;
        }
        
        input {
            width: 100%;
            padding: 10px;
            border: 2px solid #ddd;
            border-radius: 5px;
            font-size: 16px;
        }
        
        button {
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
            color: white;
            border: none;
            padding: 12px 30px;
            border-radius: 8px;
            font-size: 16px;
            cursor: pointer;
            transition: transform 0.2s;
        }
        
        button:hover {
            transform: translateY(-2px);
        }
        
        .visualization {
            margin-top: 30px;
        }
        
        .step {
            margin-bottom: 30px;
            padding: 20px;
            background: #f0f4ff;
            border-radius: 10px;
            border-left: 4px solid #667eea;
        }
        
        .step-title {
            font-weight: 700;
            color: #667eea;
            margin-bottom: 15px;
            font-size: 1.2em;
        }
        
        .array-display {
            display: flex;
            gap: 8px;
            flex-wrap: wrap;
            margin: 10px 0;
        }
        
        .array-item {
            width: 50px;
            height: 50px;
            display: flex;
            align-items: center;
            justify-content: center;
            background: white;
            border: 2px solid #667eea;
            border-radius: 8px;
            font-weight: 600;
            font-size: 18px;
            transition: all 0.3s;
        }
        
        .array-item.highlight {
            background: #ffd93d;
            border-color: #f39c12;
            transform: scale(1.1);
        }
        
        .array-item.median {
            background: #4ecdc4;
            border-color: #1b998b;
            transform: scale(1.15);
        }
        
        .result-box {
            margin-top: 30px;
            padding: 25px;
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
            border-radius: 15px;
            color: white;
            text-align: center;
        }
        
        .result-box h2 {
            margin-bottom: 10px;
        }
        
        .result-value {
            font-size: 3em;
            font-weight: 700;
        }
        
        .code-note {
            margin-top: 20px;
            padding: 15px;
            background: #fff3cd;
            border-left: 4px solid #ffc107;
            border-radius: 5px;
        }
        
        .bug-warning {
            background: #f8d7da;
            border-left-color: #dc3545;
            color: #721c24;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>📊 Median of Two Sorted Arrays</h1>
        
        <div class="input-section">
            <div class="input-group">
                <label>Array 1 (comma-separated numbers):</label>
                <input type="text" id="array1" value="1, 3, 5, 7" placeholder="e.g., 1, 3, 5, 7">
            </div>
            <div class="input-group">
                <label>Array 2 (comma-separated numbers):</label>
                <input type="text" id="array2" value="2, 4, 6, 8" placeholder="e.g., 2, 4, 6, 8">
            </div>
            <button onclick="visualize()">Visualize Algorithm</button>
        </div>
        
        <div id="visualization" class="visualization"></div>
    </div>

    <script>
        function visualize() {
            const arr1Input = document.getElementById('array1').value;
            const arr2Input = document.getElementById('array2').value;
            
            const nums1 = arr1Input.split(',').map(n => parseInt(n.trim())).filter(n => !isNaN(n));
            const nums2 = arr2Input.split(',').map(n => parseInt(n.trim())).filter(n => !isNaN(n));
            
            const viz = document.getElementById('visualization');
            viz.innerHTML = '';
            
            // Step 1: Show original arrays
            let step1 = document.createElement('div');
            step1.className = 'step';
            step1.innerHTML = `
                <div class="step-title">Step 1: Input Arrays</div>
                <p><strong>Array 1:</strong></p>
                <div class="array-display">${nums1.map(n => `<div class="array-item">${n}</div>`).join('')}</div>
                <p><strong>Array 2:</strong></p>
                <div class="array-display">${nums2.map(n => `<div class="array-item">${n}</div>`).join('')}</div>
            `;
            viz.appendChild(step1);
            
            // Step 2: Merge arrays (correctly)
            let farr = [];
            for(let i = 0; i < nums1.length; i++) {
                farr[i] = nums1[i];
            }
            // Add array 2 into farr array
            for(let j = 0; j < nums2.length; j++) {
                farr[j + nums1.length] = nums2[j];
            }
            
            let step2 = document.createElement('div');
            step2.className = 'step';
            step2.innerHTML = `
                <div class="step-title">Step 2: Merge into Single Array</div>
                <p>Combining both arrays into one (farr):</p>
                <div class="array-display">${farr.map(n => `<div class="array-item">${n}</div>`).join('')}</div>
                <div class="code-note">
                    <strong>✓ Merge Process:</strong> First, copy all elements from Array 1, then append all elements from Array 2.
                    Array 1 occupies indices 0 to ${nums1.length - 1}, Array 2 occupies indices ${nums1.length} to ${farr.length - 1}.
                </div>
            `;
            viz.appendChild(step2);
            
            // Step 3: Sorting (bubble sort)
            let sortedArr = [...farr];
            for(let i = 0; i < sortedArr.length; i++) {
                for(let k = 0; k < sortedArr.length; k++) {
                    if(sortedArr[k] > sortedArr[i]) {
                        let temp = sortedArr[k];
                        sortedArr[k] = sortedArr[i];
                        sortedArr[i] = temp;
                    }
                }
            }
            
            let step3 = document.createElement('div');
            step3.className = 'step';
            step3.innerHTML = `
                <div class="step-title">Step 3: Sort the Array</div>
                <p>Using bubble sort to arrange elements in ascending order:</p>
                <div class="array-display">${sortedArr.map(n => `<div class="array-item">${n}</div>`).join('')}</div>
            `;
            viz.appendChild(step3);
            
            // Step 4: Find median
            const s = nums1.length + nums2.length;
            const mid = Math.floor(s / 2);
            let result;
            
            if(s % 2 === 0) {
                const sum = sortedArr[mid] + sortedArr[mid - 1];
                result = sum / 2.0;
            } else {
                result = sortedArr[mid];
            }
            
            let step4 = document.createElement('div');
            step4.className = 'step';
            let medianHTML = '';
            if(s % 2 === 0) {
                medianHTML = sortedArr.map((n, i) => 
                    `<div class="array-item ${i === mid || i === mid - 1 ? 'median' : ''}">${n}</div>`
                ).join('');
            } else {
                medianHTML = sortedArr.map((n, i) => 
                    `<div class="array-item ${i === mid ? 'median' : ''}">${n}</div>`
                ).join('');
            }
            
            step4.innerHTML = `
                <div class="step-title">Step 4: Calculate Median</div>
                <p>Total elements: ${s} (${s % 2 === 0 ? 'even' : 'odd'})</p>
                <p>Middle index (mid = s/2): ${mid}</p>
                <div class="array-display">${medianHTML}</div>
                ${s % 2 === 0 ? 
                    `<div class="code-note">
                        <strong>Even number of elements:</strong><br>
                        sum = farr[mid] + farr[mid-1] = ${sortedArr[mid]} + ${sortedArr[mid - 1]} = ${sortedArr[mid] + sortedArr[mid - 1]}<br>
                        result = sum / 2.0 = ${sortedArr[mid] + sortedArr[mid - 1]} / 2.0 = ${result}
                    </div>` :
                    `<div class="code-note">
                        <strong>Odd number of elements:</strong><br>
                        result = farr[mid] = ${sortedArr[mid]}
                    </div>`
                }
            `;
            viz.appendChild(step4);
            
            // Result
            let resultBox = document.createElement('div');
            resultBox.className = 'result-box';
            resultBox.innerHTML = `
                <h2>Final Result</h2>
                <div class="result-value">${result.toFixed(2)}</div>
            `;
            viz.appendChild(resultBox);
        }
        
        // Run visualization on load
        visualize();
    </script>
</body>
</html>