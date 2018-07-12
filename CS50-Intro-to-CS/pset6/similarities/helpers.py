from nltk.tokenize import sent_tokenize
import string
punctuation = set(string.punctuation)

def lines(a, b):
    """Return lines in both a and b"""
    aLines = a.splitlines()
    bLines = b.splitlines()

    final = []
    for s in aLines:
        if s in bLines:
            final.append(s)

    # TODO
    return final


def sentences(a, b):
    """Return sentences in both a and b"""
    textA = sent_tokenize(a)
    textB = sent_tokenize(b)
    setA = set(textA)
    setB = set(textB)
    final = []
    for s in setA:
        if s in setB:
            final.append(s)

    return final

def substrings(a, b, n):
    """Return substrings of length n in both a and b"""
    lengthA = len(a)
    listA = []
    for x in range(lengthA-n+1):
        listA.append(a[x:x+n])

    lengthB = len(b)
    listB = []
    for x in range(lengthB-n+1):
        listB.append(b[x:x+n])

    setA = set(listA)
    setB = set(listB)

    answer = [];
    for str in setA:
        if str in setB:
            answer.append(str)

    return answer



#def substrings(a, b, n):
    """Return substrings of length n in both a and b"""
#    wordsA = a.split()
#   wordsA = [''.join(c for c in s if c not in punctuation) for s in wordsA]

#    wordsB = b.split()
#    wordsB = [''.join(c for c in s if c not in punctuation) for s in wordsB]

    # finalA = [];
    # for w in wordsA:
        # if len(w) < n:
            # finalA.append(w)
        # else:
            # number of words = length - n + 1
            # numWords = len(w) - n + 1
            # for x in range(numWords):
                # finalA.append(w[x:x+n])
    # dummy = []
    # finalB = [];
    # for w in wordsA:
        # if len(w) < n:
            # finalB.append(w)
            # dummy.append(w)
        # else:
            # number of words = length - n + 1
            # numWords = len(w) - n + 1
            # for x in range(numWords):
                # finalB.append(w[x:x+n])

    # setA = set(finalA)
    # setB = set(finalB)

    # answer = [];
    # for str in setA:
        # if str in setB:
            # answer.append(str)

    # print(answer)
    # print(setA)

    # return answer