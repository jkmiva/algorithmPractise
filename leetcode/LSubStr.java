/**
 * find the length of longest subString without repeated character.
 * Huang Jiaming, saskatoon
 * 5 Aug, 2016
 */
public class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.length() == 0) return 0;
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
        int max = 0, start = -1;
        // traverse the string, start index and pointers can only move forward
        for(int i=0; i<s.length(); i++){
            if (map.containsKey(s.charAt(i))){
                start = Math.max(start,map.get(s.charAt(i))); // update start index
            }
            map.put(s.charAt(i),i);
            max = Math.max(max, i-start); //store and update max
        }
        return max;
    }
}
