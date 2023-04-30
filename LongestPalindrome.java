import cn.hutool.core.lang.Pair;

public class LongestPalindrome
{
    /**
     * Finds the longest palindrome in a given string.
     * @param s The input string.
     * @return A Pair object containing the start index and length of the longest palindrome, or null if no palindrome is found.
     */
    public static Pair<Integer, Integer> findLongestPalindrome(String s)
    {
        if(s == null || s.length() < 2) return null;

        int maxLength = 1;
        int start = 0;
        char[] c = s.toCharArray();

        for(int i = 0; i != c.length; i++)
        {
            int left = i - 1;
            int right = i + 1;
            while(left >= 0 && right != c.length && c[left] == c[right])
            {
                left--;
                right++;
            }
            int length = right - left - 1;
            if(length > maxLength)
            {
                maxLength = length;
                start = left + 1;
            }

            left = i;
            right = i + 1;
            while(left >= 0 && right != c.length && c[left] == c[right])
            {
                left--;
                right++;
            }
            length = right - left - 1;
            if(length > maxLength)
            {
                maxLength = length;
                start = left + 1;
            }
        }

        return maxLength < 2 ? null : new Pair<>(start, maxLength);
    }

    public static void main(String[] args)
    {
        System.out.println(findLongestPalindrome("babadbabdadab")); // 3, 7
        System.out.println(findLongestPalindrome("cbbcd")); // 0, 4
        System.out.println(findLongestPalindrome("dad")); // 0, 3
        System.out.println(findLongestPalindrome("bb")); // 0, 2
        System.out.println(findLongestPalindrome("a")); // null
        System.out.println(findLongestPalindrome("sieqahxcoapcyameuo")); // null
    }
}
