## trick记录

### E
1. 贪心相邻交换论证：对于一种堆叠序列从上往下考虑, 假设上面堆的重量综合为 $tot$，下两个要堆的分别是 $i, j$:
    - $i$ 要放 $j$ 的上面则：

        $tot\leq D_i$， $D_j\ge W_i + tot$

        即 $tot\leq \min(D_i, D_j - Wi)$
    - $j$ 要放 $i$ 的上面则：

        $tot\leq D_j$， $D_i\ge W_j + tot$

        即 $tot\leq \min(D_j, D_i - W_j)$
    

    核心结论：

    $W_i+D_i\leq W_j+D_j$ 是 $i$ 放 $j$ 上面的堆叠可行性质不弱于 $j$ 放 $i$ 上面（即tot尽可能大，上面能放的物品就越多）的充要条件

    可以考虑必要性探路：

    如果 $i$ 放 $j$ 上面可行，反过来不成立，则 $tot>D_i-W_j$，即 $D_i-W_j<tot\leq D_j-W_i$ 一定成立，则 $W_i+D_i<W_j+D_j$，充分行也比较容易证明，所以按照 $W+D$ 从小到大排序，可以让堆叠顺序可行性最优



2. 反悔贪心：按照贪心排序之后，如果考虑能放就放，容易出现当前有一个比较重的选了之后后面的很多都选不了，我们希望在能选总数不变的情况下，前面选的总重量尽可能的小，这样后面能选的可能性才会变大，所以需要我们维护所堆叠序列中重量之和最小，这是一个经典的反悔贪心（用堆维护前k小等问题），如果出现 $D_i < tot$，则从堆里面去掉一个 $W$ 最大的即可


## python用法记录

1. python的sort用lambda
    ```python
    arr = [[1, 4], [2, 0], [4, 5]]
    # 按照x[0] + x[1]从小到大排序
    arr.sort(key=lambda x: x[0] + x[1])
    ```
2. python的堆heap使用
    ```python
    import heapq
    nums = [5, 2, 9, 1, 5, 6]
    # 1. 原地构建小顶堆（最基础，O(n) 时间）
    heapq.heapify(nums)
    # 2. 向堆中添加元素（自动维护小顶堆结构）
    heapq.heappush(nums, 3)
    # 3. 弹出堆顶最小元素（每次弹出后仍保持堆结构）
    min_num = heapq.heappop(nums)
    # 4. 直接取列表中前3个最小元素（无需手动构建堆）
    top3_small = heapq.nsmallest(3, nums)
    # 5. 实现大顶堆（取最大元素，通过负数反转）
    max_heap = []
    [heapq.heappush(max_heap, -num) for num in [5,2,9,1]]
    max_num = -heapq.heappop(max_heap)
    ```
