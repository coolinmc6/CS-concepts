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
			<td><strong><em><a href="https://github.com/coolinmc6/CS-concepts">Computer Science</a></em></strong></td>
			<td><a href="https://github.com/coolinmc6/design-ux-ui#product-design--development">Product Development</a></td>
			<td><a href="https://github.com/coolinmc6/design-ux-ui">UX / UI Design</a></td>
			<td><a href="https://github.com/coolinmc6/front-end-dev">Front End Development</a></td>
		</tr>
		<tr>
			<td></td>
			<td><em>Python Cheat Sheet</em></td>
			<td></td>
			<td></td>
			<td></td>
		</tr>		
	</tbody>
</table>

<a name="top"></a>

# Python Cheat Sheet

## Lists

#### Return Value for Playing Card

```py
# hand = "2S 3S 4S 5S 6S".split()
def card_ranks(hand):
  order = "--23456789TJQKA"
  ranks = [order.index(r) for r,s in hand]
  ranks.sort(reverse=True)
  return ranks
```

#### Uppercase a list of Names

```py
names = ['steve', 'rob', 'bob', 'sally', 'betty', 'jon']
uppercase = [name.upper() for name in names]
```


## Generators

#### Generator for Even Number Squares
```py
# nothing happens after this line
g = (sq(x) for x in range(10) if x % 2 == 0)

next(g) # sq called 2; 4
next(g) # etc.
next(g) # etc.
next(g) # etc.

next(g) # Python raises a StopIteration error

# Here is an example of returning the results in a list
list((sq(x) for x in range(10) if x % 2 == 0))
```
#### Generate All Integers Alternating Positive and Negative

```py
def all_ints():
	# Generate integers in the order 0, +1, -1, +2, -2, etc.
	yield 0
	i = 1
	while True:
		yield +i
		yield -i
		i = i + 1

```
