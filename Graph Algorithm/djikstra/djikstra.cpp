//NextGreaterElements
ll NGE[300005];

void nextGreaterElement(int arr[], int n)
{
    stack<pair<int, int>> s;
    s.push({arr[0], 0});

    for (int i = 1; i < n; i++) {

        if (s.empty()) {
            s.push({arr[i], i});
            continue;
        }
        while (s.empty() == false && s.top().fi < arr[i]) {
            nxt[s.top().se] = i;
            s.pop();
        }
        s.push({arr[i], i});
    }
    while (s.empty() == false) {
        nxt[s.top().se] = n;
        s.pop();
    }
}