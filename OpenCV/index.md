# 2.1图像入门

**cv.imread()**，**cv.imshow()**，**cv.imwrite()**

-   读取图像：cv.imread()

    第一个参数是图片地址，第二个参数是读取方式：

    -   cv.IMREAD_COLOR： 加载彩色图像。任何图像的透明度都会被忽视。它是默认标志。
    -   cv.IMREAD_GRAYSCALE：以灰度模式加载图像
    -   cv.IMREAD_UNCHANGED：加载图像，包括alpha通道

    可以使用数字1,0，-12
    
    ```python
    import cv2 as cv
    import numpy as np
    src = cv.imread("1.jpeg",1)
    ```

-   显示图像：cv.imshow()
    第一个参数是窗口的名称，是字符串；第二个参数是传递的对象.

    ```python
    cv.imshow("title",src)
    cv.waitKey(0)
    cv.destoryAllWindows()
    ```

    **cv.waitKey**()是一个键盘绑定函数。其参数是以毫秒为单位的时间。该函数等待任何键盘事件指定的毫秒。

    **cv.destroyAllWindows**()只会破坏我们创建的所有窗口。如果要销毁任何特定的窗口，请使用函数 **cv.destroyWindow**()在其中传递确切的窗口名称作为参数。

-   写入图像：cv.imwrite()

    第一个参数是文件名，第二个参数是要保存的图像。

​    总结：

```python
import cv2 as cv
src = cv.imread("1.jpeg",0)
cv.imshow("img",src)
k = cv.waitKey(0)
if k == 27:
    cv.destroyAllWindows()
elif k == ord('s'):
    cv.imwrite("1.png",src)
    cv.destroyAllWindows()
```

上面代码，以灰度加载图像，按s保存并退出，按esc退出不保存。



# 2.2视频入门

cv.VideoCapture(),cv.VideoWriter()

捕获后记得释放。

-   从相机中读取视频：cv.VideoCapture()

    ```python
    import cv2 as cv
    video = cv.VideoCapture(0)
    if not video.isOpened():
        print ("not found")
        exit(0)
    
    while True:
        #逐帧捕获
        ret,frame = video.read()。
        #正确读取的话，ret为true
        if not ret:
            break
        gray = cv.cvtColor(frame,1)
        #显示结果
        cv.imshow('title',gray)
        if cv.waitKey(1) == ord('q'):#退出
            break
    #释放捕获器
    video.release()
    cv.destroyAllWindows()
    ```

-   从文件播放视频

    >    cv.VideoCapture("xxx.avi")

-   保存视频：cv.imwrite()



















