/*
题目描述：
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。


解题思路：
该题可以用滑动窗口概念来解决，其实我更愿意叫双指针；
1.由于要查找子串，可以设个头指针head，以及尾指针tail；
2.如果字串没有重复，tail+1后移，如果找到相同的则头指针滑动到重复的位置后一个字符；
*/
int lengthOfLongestSubstring(char * s) {
	int len, sub_len = 1, max_len = 1, last_len;
	int head = 0, tail = 1, ptr = 0;

	len = last_len = strlen(s);
	if (len < 2)
		return len;
	while (max_len < last_len)
	{
		while (s[ptr] != s[tail])
		{
			sub_len++;
			if (++ptr == tail)
			{
				if (max_len < sub_len)
					max_len = sub_len;

				if (tail == (len - 1))
					return max_len;

				ptr = head;
				tail++;
				sub_len = 1;
			}

		}
		head = ptr + 1;
		ptr = head;
		tail = tail + 1;
		sub_len = 1;
		last_len = len - head;
	}

	return max_len;
}