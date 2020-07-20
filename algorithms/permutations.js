const util = require('./testing/utils');
const p01 = require('./permutations_01')
const p02 = require('./permutations_02')
const p03 = require('./permutations_03')
const p04 = require('./permutations_04')

const p1 = p01.permutations('abc'.split(''));
const p2 = p02.permutations('abc'.split(''));
const p3 = p03.permutations('abc'.split(''));
const p4 = p04.permutations('abc'.split(''));

const testArray = 'abcdefghi'.split('')

// util.timing({ name: 'p1', fn: p01.permutations, args: testArray})
// util.timing({ name: 'p2', fn: p02.permutations, args: testArray})
// util.timing({ name: 'p3', fn: p03.permutations, args: testArray})
// util.timing({ name: 'p4', fn: p04.permutations, args: testArray})

const t = [p01, p02, p03, p04]
t.map((f, i) => {
  util.timing({ name: `p${i+1}`, fn: f.permutations, args: testArray })
})
