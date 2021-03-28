[TOC]

## P2.Label & button 标签和按钮

```python
import tkinter as tk
window = tk.Tk()
window.title('my window')
window.geometry('200x100')
a = tk.Label(window, text='this is tk', bk='green', front=('Arial', 12), width=15, height=2)
a.pack()
window.mainloop()
```



## P2.entry & text



```
import tkinter as tk

window = tk.Tk()
window.title('win title')
window.geometry('200x300')
e = tk.Entry(window,show = None)
e.pack()
def insert_point():
    var = e.get()
    t.insert('insert',var)

def insert_end(): 
    var = e.get()
    e.insert('end',var)

b1 = tk.Button(window,text = 'inset point',width=15,height=2,command = insert_point)
b2 = tk.Button(window,text = 'insert end',height = 2,command = insert_end)
b1.pack()
b2.pack()
t = tk.Text(window,height = 2)
t.pack()

window.mainloop()
```

