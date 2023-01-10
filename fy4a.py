import requests
#import time
import os
from PIL import Image

file_cache= os.environ['HOME'] + '/data/fy4a/pic/cache_wallpaper.jpg'
file_final= os.environ['HOME'] + '/data/fy4a/pic/final.jpg'

def checkDir(download_path):
  mkdirlambda = lambda x: os.makedirs(x) if not os.path.exists(x) else True  # 目录是否存在,不存在则创建
  mkdirlambda(download_path)


def crawlWallpaper(download_path = "pic"):
  checkDir(download_path)
  picture_url = 'http://img.nsmc.org.cn/CLOUDIMAGE/FY4A/MTCC/FY4A_DISK.JPG'
  res = requests.get(picture_url)
  with open(os.path.join(download_path, './cache_wallpaper.jpg'), 'wb') as f:
    f.write(res.content)


img = Image.open(file_cache)
imgSize = img.size
w = img.width
h = img.height


def redraw_upper_left(path, earth_w, earth_h):
    # size = 1920, 1080
    image1 = Image.new("RGB", (int(260 * earth_w / 1080), int(80 * earth_h / 1080)))

    image2 = Image.open(path)
    image2 = image2.resize((earth_w, earth_h), )

    image2.paste(image1, (0, 0))

    newpath = os.path.dirname(path) + '/final' + os.path.splitext(path)[1]
    image2.save(newpath, "JPEG")
    return newpath

def redraw_bottom_right(path, earth_w, earth_h):
    # size = 1920, 1080
    image1 = Image.new("RGB", (int(250 * earth_w / 1080), int(80 * earth_h / 1080)))

    image2 = Image.open(path)
    image2 = image2.resize((earth_w, earth_h), )

    # image.thumbnail(size)
    bw, bh = image1.size
    lw, lh = image2.size

    image2.paste(image1, (lw - bw, lh - bh))

    newpath = os.path.dirname(path) + '/final' + os.path.splitext(path)[1]
    image2.save(newpath, "JPEG")
    return newpath

def redraw_left_right(path, screen_w, screen_h, earth):
    # size
    image1 = Image.new("RGB", (screen_w, screen_h))

    image2 = Image.open(path)
    image2 = image2.resize((earth, earth), )

    # image.thumbnail(size)
    bw, bh = image1.size
    lw, lh = image2.size
    image1.paste(image2, (int((bw - lw) / 2), int((bh - lh) / 2)))

    newpath = os.path.dirname(path) + '/final' + os.path.splitext(path)[1]
    image1.save(newpath, "PNG")
    return newpath

if __name__ == '__main__':
    crawlWallpaper()
    redraw_upper_left(file_cache, w, h)
    redraw_bottom_right(file_final, w, h)
    redraw_left_right(file_final, w, h, 1200)

os.system('feh --bg-fill /data/fy4a/pic/final.jpg')
print("OK")

