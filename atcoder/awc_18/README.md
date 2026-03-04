### python用法记录

1. python的enumerate可以在遍历可迭代对象的同时返回索引下标
    ```python
    arr = [1, 4, 2, 5]
    for idx, val in enumerate(arr):
        print(f"idx: {idx}, val: {val}")
        # 0, 1
        # 1, 4
        # 2, 2
        # 3, 5
    ```
2. python离散化写法
    ```python
    arr = [4, 2, 1, 3, 3, 3]
    # 排序去重
    sorted_arr = sorted(set(arr))
    # 获取rank字典
    rank_dict = {val: i + 1 for i, val in enumerate(sorted_arr)}
    # 获取离散化后的数组
    compressed_arr = [rank_dict[val] for val in arr]
    ```
2. python的ASCII码和char互转
    ```python
    ord_a = ord('a') # 转 ASCII
    chr_a = char(ord_a) # 转char
    ```
3. python的字符串是不可变类型，如需修改需要转成list
4. python的join用法
    ```python
    # join 可以将一个可迭代对象中的所有字符串元素，按指定分割符拼接成一个字符串
    v = ['a', 'b', 'c']
    print(''.join(v)) # "abc"
    print('-'.jon(v)) # "a-b-c"
    ```
5. 遍历字典的(key, value)，使用 dict.items()
    ```python
    test_dict = {"a": 1, "b": 2, "c": 3}
    for key, value in test_dict.items():
        print(f"key: {key}, value: {value}")
    ```
