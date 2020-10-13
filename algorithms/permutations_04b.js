const permutations = array => {
  // CM - I don't get this
  array.sort();

  // CM - add original array?
  let perms = [array.slice()];

  while(array) {
    let [i, j, k] = Array(3).fill(array.length - 1);
    // console.log({ array: array.slice(), i, j, k})

    break;
  }



  return perms;
}

module.exports = {
  permutations
}