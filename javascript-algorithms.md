<table>
	<thead>
		<tr>
			<th colspan="5" style="text-align: center;"><strong>Subjects of Study</strong></th>
		</tr>
		<tr>
			<td colspan="5">The links below are to the parent GitHub repos of completed courses, resources, my own notes, links to articles, etc. about the topics shown below. They are designed to be my "go-to" place for teaching myself the given subject.</td>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td><a href="https://github.com/coolinmc6/analytics">Analytics</a></td>
			<td><a href="https://github.com/coolinmc6/CS-concepts"><strong><em>Computer Science</em></strong></a></td>
			<td><a href="https://github.com/coolinmc6/design-ux-ui#product-design--development">Product Development</a></td>
			<td><a href="https://github.com/coolinmc6/design-ux-ui">UX / UI Design</a></td>
			<td><a href="https://github.com/coolinmc6/front-end-dev">Front End Development</a></td>
		</tr>
		<tr>
			<td></td>
			<td><a href="https://github.com/coolinmc6/CS-concepts/blob/master/algorithm-data-structures-interview.md">Algorithm & Data Structures Interview</a></td>
			<td></td>
			<td></td>
			<td></td>
		</tr>
		<tr>
		  <td></td>
		  <td><a href="https://github.com/coolinmc6/CS-concepts/blob/master/data-structures.md">Data Structures (in JavaScript)</a></td>
		  <td></td>
		  <td></td>
		  <td></td>
		</tr>
		<tr>
			<td></td>
			<td><em>JavaScript Algorithms</em></td>
			<td></td>
			<td></td>
			<td></td>
		</tr>		
	</tbody>
</table>

### Get All Permutations of an Array

```js
function permute(permutation) {
  var length = permutation.length,
      result = [permutation.slice()],
      c = new Array(length).fill(0),
      i = 1, k, p;

  while (i < length) {
    if (c[i] < i) {
      k = i % 2 && c[i];
      p = permutation[i];
      permutation[i] = permutation[k];
      permutation[k] = p;
      ++c[i];
      i = 1;
      result.push(permutation.slice());
    } else {
      c[i] = 0;
      ++i;
    }
  }
  return result;
}
```

### Get All Permutations of a String

```js
function getAllPermutations(string) {
	var results = [];

	if (string.length === 1) {
		results.push(string);
		return results;
	}

	for (var i = 0; i < string.length; i++) {
		var firstChar = string[i];
		var charsLeft = string.substring(0, i) + string.substring(i + 1);
		var innerPermutations = getAllPermutations(charsLeft);
		for (var j = 0; j < innerPermutations.length; j++) {
			results.push(firstChar + innerPermutations[j]);
		}
	}
	return results;
}

let permutations = getAllPermutations('abcdef')
console.log(permutations) // Array (720) 
```

### Shuffle an Array

```js
function shuffle(array) {
  for (let i = array.length - 1; i > 0; i--) {
    let j = Math.floor(Math.random() * (i + 1)); // random index from 0 to i

    // swap elements array[i] and array[j]
    // we use "destructuring assignment" syntax to achieve that
    // same can be written as:
    // let t = array[i]; array[i] = array[j]; array[j] = t
    [array[i], array[j]] = [array[j], array[i]];
  }
}
```

Source: [https://javascript.info/task/shuffle](https://javascript.info/task/shuffle)


