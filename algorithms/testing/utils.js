const timing = ({ name, fn, args }) => {
  console.time(name);
  const res = fn(args);
  console.timeEnd(name);
  return res;
}

module.exports = {
  timing
}