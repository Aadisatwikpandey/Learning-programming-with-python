// 1. Two Sum
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

 

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]
 

// Constraints:

// 2 <= nums.length <= 104
// -109 <= nums[i] <= 109
// -109 <= target <= 109
// Only one valid answer exists.
 

// Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?



//Solution

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int sum;
    int* output=malloc(2 * sizeof(int));
    * returnSize=2;

    for(int j=0;j<numsSize;j++){
        for(int k=1;k<numsSize;k++){
            sum = nums[j]+nums[k];
            if (sum==target){
                output[0]=j;
                output[1]=k;
                return output;
            }
            else{
                sum=0;
            }
        }
    }
    return NULL;
}





//Visualize Execution:
//React file for visualizing code execution: 
/*
import React, { useState } from 'react';
import { Play, RotateCcw, SkipForward, Pause } from 'lucide-react';

export default function TwoSumVisualizer() {
  const [nums, setNums] = useState([2, 7, 11, 15]);
  const [target, setTarget] = useState(9);
  const [inputNums, setInputNums] = useState('2,7,11,15');
  const [inputTarget, setInputTarget] = useState('9');
  const [j, setJ] = useState(0);
  const [k, setK] = useState(1);
  const [sum, setSum] = useState(0);
  const [result, setResult] = useState(null);
  const [isRunning, setIsRunning] = useState(false);
  const [isComplete, setIsComplete] = useState(false);

  const reset = () => {
    setJ(0);
    setK(1);
    setSum(0);
    setResult(null);
    setIsRunning(false);
    setIsComplete(false);
  };

  const updateArray = () => {
    const newNums = inputNums.split(',').map(n => parseInt(n.trim())).filter(n => !isNaN(n));
    const newTarget = parseInt(inputTarget);
    if (newNums.length > 0 && !isNaN(newTarget)) {
      setNums(newNums);
      setTarget(newTarget);
      reset();
    }
  };

  const step = () => {
    if (isComplete) return;

    // Check if accessing out of bounds
    if (j > nums.length || k > nums.length) {
      setResult('ERROR: Array index out of bounds!');
      setIsComplete(true);
      setIsRunning(false);
      return;
    }

    const currentSum = nums[j] + nums[k];
    setSum(currentSum);

    if (currentSum === target) {
      setResult([j, k]);
      setIsComplete(true);
      setIsRunning(false);
      return;
    }

    let nextK = k + 1;
    let nextJ = j;

    if (nextK > nums.length) {
      nextJ = j + 1;
      nextK = 1;
    }

    if (nextJ > nums.length) {
      setResult(null);
      setIsComplete(true);
      setIsRunning(false);
      return;
    }

    setK(nextK);
    setJ(nextJ);
  };

  const autoRun = () => {
    if (!isRunning) {
      setIsRunning(true);
    }
  };

  React.useEffect(() => {
    if (isRunning && !isComplete) {
      const timer = setTimeout(step, 500);
      return () => clearTimeout(timer);
    }
  }, [isRunning, j, k, isComplete]);

  const pauseRun = () => {
    setIsRunning(false);
  };

  return (
    <div className="min-h-screen bg-gradient-to-br from-slate-900 via-blue-900 to-slate-900 p-8">
      <div className="max-w-5xl mx-auto">
        <h1 className="text-4xl font-bold text-white mb-2 text-center">Two Sum Algorithm Visualizer</h1>
        <p className="text-blue-200 text-center mb-8">Watch how the nested loop searches for two indices</p>


        <div className="bg-slate-800 rounded-lg p-6 mb-6 shadow-2xl border border-blue-500/30">
          <div className="grid grid-cols-1 md:grid-cols-2 gap-4 mb-4">
            <div>
              <label className="text-blue-200 text-sm mb-2 block">Array (comma-separated)</label>
              <input
                type="text"
                value={inputNums}
                onChange={(e) => setInputNums(e.target.value)}
                className="w-full px-4 py-2 bg-slate-700 text-white rounded border border-blue-500/50 focus:border-blue-400 outline-none"
                placeholder="2,7,11,15"
              />
            </div>
            <div>
              <label className="text-blue-200 text-sm mb-2 block">Target</label>
              <input
                type="text"
                value={inputTarget}
                onChange={(e) => setInputTarget(e.target.value)}
                className="w-full px-4 py-2 bg-slate-700 text-white rounded border border-blue-500/50 focus:border-blue-400 outline-none"
                placeholder="9"
              />
            </div>
          </div>
          <button
            onClick={updateArray}
            className="w-full px-4 py-2 bg-blue-600 hover:bg-blue-700 text-white rounded font-semibold transition"
          >
            Update & Reset
          </button>
        </div>

       
        <div className="bg-slate-800 rounded-lg p-6 mb-6 shadow-2xl border border-blue-500/30">
          <h2 className="text-xl font-bold text-white mb-4">Array: nums[]</h2>
          <div className="flex flex-wrap gap-3 justify-center">
            {nums.map((num, idx) => (
              <div key={idx} className="relative">
                <div className={`w-16 h-16 flex items-center justify-center rounded-lg text-xl font-bold transition-all ${
                  idx === j && idx === k ? 'bg-purple-500 text-white scale-110 shadow-lg shadow-purple-500/50' :
                  idx === j ? 'bg-green-500 text-white scale-110 shadow-lg shadow-green-500/50' :
                  idx === k ? 'bg-yellow-500 text-white scale-110 shadow-lg shadow-yellow-500/50' :
                  'bg-slate-700 text-blue-200'
                }`}>
                  {num}
                </div>
                <div className="text-center text-blue-300 text-sm mt-1">index {idx}</div>
                {idx === j && <div className="text-center text-green-400 text-xs font-bold">j</div>}
                {idx === k && idx !== j && <div className="text-center text-yellow-400 text-xs font-bold">k</div>}
              </div>
            ))}
          </div>
        </div>

        
        <div className="bg-slate-800 rounded-lg p-6 mb-6 shadow-2xl border border-blue-500/30">
          <h2 className="text-xl font-bold text-white mb-4">Current Execution State</h2>
          <div className="grid grid-cols-2 md:grid-cols-4 gap-4">
            <div className="bg-slate-700 rounded p-4">
              <div className="text-blue-300 text-sm">j (outer loop)</div>
              <div className="text-2xl font-bold text-green-400">{j}</div>
            </div>
            <div className="bg-slate-700 rounded p-4">
              <div className="text-blue-300 text-sm">k (inner loop)</div>
              <div className="text-2xl font-bold text-yellow-400">{k}</div>
            </div>
            <div className="bg-slate-700 rounded p-4">
              <div className="text-blue-300 text-sm">sum</div>
              <div className="text-2xl font-bold text-white">{sum}</div>
            </div>
            <div className="bg-slate-700 rounded p-4">
              <div className="text-blue-300 text-sm">target</div>
              <div className="text-2xl font-bold text-blue-400">{target}</div>
            </div>
          </div>
          
          <div className="mt-4 bg-slate-900 rounded p-4 font-mono text-sm">
            <div className="text-blue-300">Current calculation:</div>
            {(j > nums.length - 1 || k > nums.length - 1) ? (
              <div className="text-red-400 mt-2 font-bold">
                ⚠️ ERROR: Accessing nums[{j > nums.length - 1 ? j : k}] but array size is {nums.length}!
                <div className="text-sm mt-1">This causes undefined behavior (array out of bounds)</div>
              </div>
            ) : (
              <>
                <div className="text-white mt-2">
                  sum = nums[{j}] + nums[{k}] = {nums[j]} + {nums[k]} = {sum}
                </div>
                {sum === target && !isComplete && (
                  <div className="text-green-400 mt-2 font-bold">✓ sum == target! Found the answer!</div>
                )}
                {sum !== target && (
                  <div className="text-red-400 mt-2">✗ sum != target, continue searching...</div>
                )}
              </>
            )}
          </div>
        </div>

        
        <div className="bg-slate-800 rounded-lg p-6 mb-6 shadow-2xl border border-blue-500/30">
          <div className="flex flex-wrap gap-3 justify-center">
            <button
              onClick={autoRun}
              disabled={isComplete || isRunning}
              className="px-6 py-3 bg-green-600 hover:bg-green-700 disabled:bg-slate-600 disabled:cursor-not-allowed text-white rounded-lg font-semibold flex items-center gap-2 transition"
            >
              <Play size={20} /> Auto Run
            </button>
            <button
              onClick={pauseRun}
              disabled={!isRunning}
              className="px-6 py-3 bg-orange-600 hover:bg-orange-700 disabled:bg-slate-600 disabled:cursor-not-allowed text-white rounded-lg font-semibold flex items-center gap-2 transition"
            >
              <Pause size={20} /> Pause
            </button>
            <button
              onClick={step}
              disabled={isComplete || isRunning}
              className="px-6 py-3 bg-blue-600 hover:bg-blue-700 disabled:bg-slate-600 disabled:cursor-not-allowed text-white rounded-lg font-semibold flex items-center gap-2 transition"
            >
              <SkipForward size={20} /> Step
            </button>
            <button
              onClick={reset}
              className="px-6 py-3 bg-purple-600 hover:bg-purple-700 text-white rounded-lg font-semibold flex items-center gap-2 transition"
            >
              <RotateCcw size={20} /> Reset
            </button>
          </div>
        </div>

       
        {isComplete && (
          <div className="bg-slate-800 rounded-lg p-6 shadow-2xl border border-blue-500/30">
            <h2 className="text-xl font-bold text-white mb-4">Result</h2>
            {typeof result === 'string' ? (
              <div className="bg-red-900/30 border border-red-500 rounded p-4">
                <div className="text-red-400 text-lg font-bold mb-2">⚠️ Runtime Error</div>
                <div className="text-white">{result}</div>
                <div className="text-red-300 mt-2 text-sm">
                  The loop conditions j≤numsSize and k≤numsSize cause out-of-bounds access.
                  Array indices should be 0 to numsSize-1.
                </div>
              </div>
            ) : result ? (
              <div className="bg-green-900/30 border border-green-500 rounded p-4">
                <div className="text-green-400 text-lg font-bold mb-2">✓ Solution Found!</div>
                <div className="text-white">
                  <div>output[0] = {result[0]}</div>
                  <div>output[1] = {result[1]}</div>
                  <div className="mt-2 text-blue-200">
                    nums[{result[0]}] + nums[{result[1]}] = {nums[result[0]]} + {nums[result[1]]} = {target}
                  </div>
                </div>
              </div>
            ) : (
              <div className="bg-red-900/30 border border-red-500 rounded p-4">
                <div className="text-red-400 text-lg font-bold">✗ No Solution Found</div>
                <div className="text-white">return NULL</div>
              </div>
            )}
          </div>
        )}

       
        <div className="bg-slate-800 rounded-lg p-6 mt-6 shadow-2xl border border-blue-500/30">
          <h2 className="text-xl font-bold text-white mb-3">How It Works (with Bugs)</h2>
          <div className="text-blue-200 space-y-2">
            <p><span className="text-green-400 font-bold">j (green)</span> - Outer loop: j starts at 0, goes to j≤numsSize</p>
            <p><span className="text-yellow-400 font-bold">k (yellow)</span> - Inner loop: k starts at 1, goes to k≤numsSize</p>
            <p>For each pair (j, k), it calculates sum = nums[j] + nums[k]</p>
            <p>If sum equals target, it returns the indices [j, k]</p>
            <p className="text-red-300 font-bold mt-3">⚠️ BUGS IN THIS CODE:</p>
            <p className="text-red-300">1. Loop conditions use ≤ instead of &lt; causing array out-of-bounds</p>
            <p className="text-red-300">2. When numsSize=4, valid indices are 0-3, but loops try to access index 4</p>
            <p className="text-red-300">3. k starts at 1, skipping the pair (0, 0)</p>
            <p className="text-orange-300 italic">Note: This algorithm has O(n²) time complexity</p>
          </div>
        </div>
      </div>
    </div>
  );
}
*/