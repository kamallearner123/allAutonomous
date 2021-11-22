import cv2
import datetime


def get_file_name ():
    return str(datetime.datetime.now()).replace("-","_").replace(":","_").replace(" ","").replace(".","")


def get_quote_of_person(cam, img_name):
    ret, frame = cam.read()
    print("Image file name: {}", img_name)
    cv2.imwrite(img_name+".jpg", frame)
    return 0


print("Importing \"iseeyou\" module imported properly :)")