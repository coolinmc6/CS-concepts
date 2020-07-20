
function permutations(arr) {
  const results = []
  if(arr.length === 1) {
    let t = results.concat(arr);
    // console.log({msg: "Return Single Array", t, arr, results })
    return t;
  }

  for(let i = 0; i < arr.length; i++) {
    const first = arr[i];
    const others = [...arr.slice(0, i), ...arr.slice(i+1)]
    let oPerms = permutations(others);

    for(let j = 0; j < oPerms.length; j++) {
      let t = [first, ...oPerms[j]]
      results.push(t);
    }
  }
  return results;

}

module.exports = {
  permutations
}