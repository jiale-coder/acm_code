## python技巧

1. python的 `defaultdict` 用法
  ```python
  from collections import defaultdict
  mp_int = defaultdict(int)
  mp_list = defaultdict(list)
  # 多维defaultdict创建例子:
  # 由于defaultdict要求参数是一个可调用的无参可调用对象: defaultdict(X), 比如函数、lambda，所以这里得使用lambda返回defaultdict(int)
  # 当defaultdict不存在键时，会自动调用 X() 构造键默认值
  mp_dims = defaultdict(lambda: defaultdict(int))
  mp_dims[3][4] += 12
  ```
2. python线段树模板
  ```python
  class Tag:
    def __init__(self, lazy: int = 0):
      self.lazy = lazy

    def apply(self, v: "Tag"):
      self.lazy += v.lazy

  class Info:
    def __init__(self, sum: int = 0, len: int = 0):
      self.sum = sum
      self.len = len

    def apply(self, v: Tag):
      self.sum += v.lazy * self.len

    def __add__(self, other: "Info") -> "Info":
      res = Info()
      res.sum = self.sum + other.sum
      res.len = self.len + other.len
      return res

  class SegmentTree:
    def __init__(self, n: int, info_list: list[Info]):
      self.n = n
      self.tree = [Info() for i in range(4 * n + 1)]
      self.tag = [Tag() for i in range(4 * n + 1)]
      self.info_list = info_list
      self.build(1, 1, n)

    def pull(self, u: int):
      self.tree[u] = self.tree[u << 1] + self.tree[u << 1 | 1]

    def push(self, u: int):
      if self.tag[u] != Tag():
        self.tree[u << 1].apply(self.tag[u])
        self.tree[u << 1 | 1].apply(self.tag[u])
        self.tag[u << 1].apply(self.tag[u])
        self.tag[u << 1 | 1].apply(self.tag[u])
        self.tag[u] = Tag()
    
    def build(self, u: int, l: int, r: int):
      if l == r:
        self.tree[u] = self.info_list[l]
        return
      mid = (l + r) >> 1
      self.build(u << 1, l, mid)
      self.build(u << 1 | 1, mid + 1, r)
      self.pull(u)
    
    def modify(self, u: int, l: int, r: int, ql: int, qr: int, v: Tag):
      if l >= ql and r <= qr:
        self.tree[u].apply(v)
        self.tag[u].apply(v)
        return
      self.push(u)
      mid = (l + r) >> 1
      if ql <= mid:
        self.modify(u << 1, l, mid, ql, qr, v)
      if qr > mid:
        self.modify(u << 1 | 1, mid + 1, r, ql, qr, v)
      self.pull(u)
    
    def query(self, u: int, l: int, r: int, ql: int, qr: int) -> Info:
      if l >= ql and r <= qr:
        return self.tree[u]
      self.push(u)
      mid = (l + r) >> 1
      if qr <= mid:
        return self.query(u << 1, l, mid, ql, qr)
      elif ql > mid:
        return self.query(u << 1 | 1, mid + 1, r, ql, qr)
      return self.query(u << 1, l, mid, ql, qr) + self.query(u << 1 | 1, mid + 1, r, ql, qr)
  ```
3. python函数内修改变量的作用域规则
  ```python
    from collections import defaultdict
    # 全局变量：不可变+容器
    total, mp = 0, defaultdict(int)
    def outer():
      cnt, lst = 0, [1]
      def inner():
          nonlocal cnt; cnt += 1  # nonlocal修改外层int
          lst.append(2)  # 改列表无需nonlocal
      inner()
      print(f"nonlocal: {cnt}, 列表: {lst}")

    def global_demo():
      global total; total += 1  # global修改全局int
      mp["k"] += 1  # 改字典无需global
    outer()
    global_demo()
    print(f"global: {total}, 字典: {mp}")
  ```
4. python的sort的key用法
 ```python
  # key必须接受一个函数(lambda, 内置函数，自定义函数), 函数返回值是一个可比较大小的对象
  # 该函数会依次用到列表的每个元素上，得到一个排序键值
  # 元组列表，每个元组是(姓名, 年龄, 成绩)
  students = [("张三", 18, 90), ("李四", 17, 95), ("王五", 18, 88)]

  # 按年龄（第2个元素）升序排序
  students.sort(key=lambda x: x[1])
  print("按年龄排序：", students)  # [("李四",17,95), ("张三",18,90), ("王五",18,88)]

  # 先按年龄，再按成绩（降序需结合reverse=True）
  students.sort(key=lambda x: (x[1], -x[2]))  # 成绩降序→取负后升序
  print("按年龄+成绩排序：", students)  # [("李四",17,95), ("张三",18,90), ("王五",18,88)]

  # 复杂的排序可以自定义函数

  def cmp(item):
    name, age, score = item
    if age <= 18 and score % 2 == 0:
      return (score, name)
    return (name, score)
  
  students.sort(key=cmp)


  # cmp_to_key
  from functools import cmp_to_key
  arr = [(1, "gg"), (3, "1sxx"), (3, "s233")]
  # 必须返回int, < 0 表示 a 应该排 b 前面
  def cmp(a, b):
    if a[0] != b[0]:
      return a[0] - b[0]
    if a[1] < b[1]:
      return 1
    elif a[1] == b[1]:
      return 0
    return -1
  arr.sort(key=cmp_to_key(cmp))
 ```