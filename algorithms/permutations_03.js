// Random Permutation Algorithm
const permutations = array => {
  if (array.length < 2) {
    // Base case, return single-element array wrapped in another array
    return [array];
  } else {
    let perms = [];
    for (let index = 0; index < array.length; index++) {
      // Make a fresh copy of the passed array and remove the current element from it
      let rest = array.slice();
      rest.splice(index, 1);

      // Call our function on that sub-array, storing the result: an array of arrays
      let ps = permutations(rest);

      // Add the current element to the beginning of each sub-array and add the new
      // permutation to the output array
      const current = [array[index]]
      for (let p of ps) {
        perms.push(current.concat(p));
      }
    };
    return perms;
  }
};

// const p = permutations('abc'.split(''));
// console.log(p);

module.exports = {
  permutations
}