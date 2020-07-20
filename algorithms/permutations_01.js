// Francis's permutation algorithm
function permutations(arr) {
  if (arr.length === 1) return [arr];
  return arr.reduce((acc, curr, index) => {
    const perms = permutations([...arr.slice(0, index), ...arr.slice(index + 1, arr.length)]);
    return [...acc, ...perms.map(permutation => [curr, ...permutation])];
  }, []);
}

// const p = permutations('abc'.split(''))
// console.log(p);

module.exports = {
  permutations
}