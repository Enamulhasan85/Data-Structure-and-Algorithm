void manacher(string s) // Time Complexity: O(n)
{
    string arr;
    for (int i = 0; i < s.size(); i++)
    {
        arr.push_back('#');
        arr.push_back(s[i]);
    }
    arr.push_back('#');
    // dp[i] = palindromic substring length centered at i (with '#')
    vector<int> dp(arr.size());
    int left = 0, right = 0;
    for (int i = 0; i < arr.size();)
    {
        while (left > 0 && right < arr.size() - 1 && arr[left - 1] == arr[right + 1])
            left--, right++;
        dp[i] = right - left + 1;
        int new_center = right + (i % 2 == 0 ? 1 : 0);
        for (int j = i + 1; j <= right; j++)
        {
            dp[j] = min(dp[i - (j - i)], 2 * (right - j) + 1);
            if (j + dp[i - (j - i)] / 2 == right)
            {
                new_center = j;
                break;
            }
        }
        i = new_center;
        right = i + dp[i] / 2;
        left = i - dp[i] / 2;
    }
    int mx = 0, idx;
    for(int i=0;i<dp.size();i++)
    {
        cout<<dp[i]<<' ';
        if(mx<dp[i])
        {
            mx = dp[i];
            idx = i;
        }
    }
    string ans = "";
    for (int j = idx - dp[idx] / 2; j <= idx + dp[idx] / 2; j++)
    {
        if (arr[j] != '#') ans.push_back(arr[j]);
    }
    cout<<ans;
}