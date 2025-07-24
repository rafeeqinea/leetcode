class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """

        # If their lengths are not equal, they can't be anagrams
        if len(s) != len(t):
            return False

        # Create a dictionary to count characters in 's'
        count = {}

        for char in s:
            if char in count:
                count[char] += 1
            else:
                count[char] = 1

        # Subtract character counts using string 't'
        for char in t:
            if char not in count:
                return False
            count[char] -= 1
            if count[char] < 0:
                return False

        # All counts must end up zero
        return True

