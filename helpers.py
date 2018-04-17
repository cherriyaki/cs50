from nltk.tokenize import sent_tokenize


def lines(a, b):
    """Return list of lines in both a and b"""

    llist = list()

    """For each line in a, search if it has an index in b. If not, continue to next line in a"""
    for x in a.splitlines():

        try:

            if (b.splitlines()).index(x) >= 0:

                if llist.count(x) < 1:

                    llist.append(x)

        except:

            continue

    return llist


def sentences(a, b):
    """Return list of sentences in both a and b"""

    slist = list()

    """For each sentence in a, search if it has an index in b. If not, continue to next sentence in a"""
    for x in sent_tokenize(a):

        try:

            if (sent_tokenize(b)).index(x) >= 0:

                if slist.count(x) < 1:

                    slist.append(x)

        except:

            continue

    return slist


def ssbreak(s, n):
    """Return list of subtrings of length n in string s"""

    issls = list()

    """For each index in string, if substring from it is within string, add substring to list"""
    for i in range(0, len(s)):

        if i + n <= len(s):

            issls.append(s[i:i + n])

    return issls


def substrings(a, b, n):
    """Return list of substrings of length n in both a and b"""

    sslist = list()

    """For each substring in a, search if it has index in b. If not, continue to next substring in a"""
    for x in ssbreak(a, n):

        try:

            if (ssbreak(b, n)).index(x) >= 0:

                if sslist.count(x) < 1:

                    sslist.append(x)

        except:

            continue

    return sslist
