class Solution(object):
    def groupAnagrams(self, strs):
        result = {}  # normal dictionary

        for word in strs:
            # Step 1: Sort the word to get a consistent key
            key = ''.join(sorted(word))  # 'eat' -> 'aet'

            # Step 2: Check if key exists in dictionary
            if key in result:
                result[key].append(word)  # add word to existing list
            else:
                result[key] = [word]  # create a new list with this word

        # Step 3: Return all the grouped anagrams as a list of lists
        return list(result.values())

