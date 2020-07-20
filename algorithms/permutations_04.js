const permutations = array => {
  // Sort the input
  array.sort();
  // Add a copy and initialize our list of permutations
  let perms = [array.slice()];

  while (array) {
    let [i, j, k] = Array(3).fill(array.length - 1);

    // Find the first non-increasing element
    while (i > 0 && array[i - 1] >= array[i]) i--;
    // If we don't find one, we're done!
    if (i <= 0) break;

    // Find first element larger 
    while (array[j] <= array[i - 1]) j--;

    // Swap them
    [array[i - 1], array[j]] = [array[j], array[i - 1]];

    // Reverse the suffix
    while (i < k) {
      [array[i], array[k]] = [array[k], array[i]];
      i++;
      k--;
    }
    // Add a copy of the current state of the array to the list of permutations
    perms.push(array.slice());
  }
  return perms;
};

// const p = permutations('abc'.split(''))
// console.log(p);
module.exports = {
  permutations
}