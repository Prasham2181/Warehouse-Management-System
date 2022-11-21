import paho.mqtt.client as mqtt
import numpy as np
from pyzbar.pyzbar import decode
import pandas as pd
import cv2
import imutils
import sys
import os
import argparse
import time
from imutils.video import VideoStream
city1 = ""
city2 = ""
message = ""
broker = "192.168.1.101"
port = 2222

i = 0
j = 0
k = 0
i1 = 0
j1 = 0
k1 = 0
i2 = 0
j2 = 0
k2 = 0

df = pd.read_excel('Sample Data.xlsx')


def on_connect(publisher, userdata, flags, rc):  # The callback for when the client connects to the broker
    print("Connected with result code {0}".format(str(rc)))  # Print result of connection attempt
    publisher.subscribe("PYTHON/PUBLISH")  # Subscribe to the topic “digitest/test1”, receive any messages published on it


def on_message(publisher, userdata, msg):  # The callback for when a PUBLISH message is received from the server.
    message = str(msg.payload.decode("utf-8"))
    print("Message received: ", message)  # Print a received msg
    global i
    global j
    global k
    global i1
    global j1
    global k1
    global i2
    global j2
    global k2
    if(message == "RB1XFWD"):
        # print(message)
        print("start1")
        i = 0
    if (message == "RB2XFWD"):
        # print(message)
        print("start2")
        i1 = 0
    if (message == "RB3XFWD"):
        # print(message)
        print("start3")
        i2 = 0
    # RB3 ARUCO 2
    if (message == "RB3XDRPABADI1"):
        print(message)
        while (j2 == 0):
            # print("loop")
            publisher.publish("RB3/ROBO3", "RB3XRETABAD1")
            j2 = j2 + 1
            i2 = 0
            print('j2', j2)
            print('i2', i2)
    if (message == "RB3XDRPMUMBAII1"):
        print(message)
        while (j2 == 0):
            publisher.publish("RB3/ROBO3", "RB3XRETMUMBAI1")
            j2 = j2 + 1
            i2 = 0
            print('j2', j2)
            print('i2', i2)

    if (message == "RB3XDRPPUNEI1"):
        print(message)
        while (j2 == 0):
            publisher.publish("RB3/ROBO3", "RB3XRETPUNE1")
            i2 = 0
            j2 = j2 + 1
            print('j2', j2)
            print('i2', i2)

    if (message == "RB3XDRPJAIPURI1"):
        print(message)
        while (j2 == 0):
            publisher.publish("RB3/ROBO3", "RB3XRETJAIPUR1")
            i2 = 0
            j2 = j2 + 1
            print('j2', j2)
            print('i2', i2)

    if (message == "RB3XDRPDELHII1"):
        print(message)
        while (j2 == 0):
            publisher.publish("RB3/ROBO3", "RB3XRETDELHI1")
            i2 = 0
            j2 = j2 + 1
            print('j2', j2)
            print('i2', i2)

    if (message == "RB3XDRPBENGI1"):
        print(message)
        while (j2 == 0):
            publisher.publish("RB3/ROBO3", "RB3XRETBENG1")
            i2 = 0
            j2 = j2 + 1
            print('j2', j2)
            print('i2', i2)

    if (message == "RB3XDRPHYDERI1"):
        print(message)
        while (j2 == 0):
            publisher.publish("RB3/ROBO3", "RB3XRETHYDER1")
            i2 = 0
            j2 = j2 + 1
            print('j2', j2)
            print('i2', i2)

    if (message == "RB3XDRPKOLKATAI1"):
        print(message)
        while (j2 == 0):
            publisher.publish("RB3/ROBO3", "RB3XRETKOLKATA1")
            i2 = 0
            j2 = j2 + 1
            print('j2', j2)
            print('i2', i2)

    if (message == "RB3XDRPCHENNAII1"):
        print(message)
        while (j2 == 0):
            publisher.publish("RB3/ROBO3", "RB3XRETCHENNAI1")
            i2 = 0
            j2 = j2 + 1
            print('j2', j2)
            print('i2', i2)

    # RB3 ARUCO 2
    if (message == "RB3XDRPABADI2"):
        print(message)
        while (j2 == 0):
            # print("loop")
            publisher.publish("RB3/ROBO3", "RB3XRETABAD2")
            j2 = j2 + 1
            i2 = 0
            print('j2', j2)
            print('i2', i2)
    if (message == "RB3XDRPMUMBAII2"):
        print(message)
        while (j2 == 0):
            publisher.publish("RB3/ROBO3", "RB3XRETMUMBAI2")
            j2 = j2 + 1
            i2 = 0
            print('j2', j2)
            print('i2', i2)

    if (message == "RB3XDRPPUNEI2"):
        print(message)
        while (j2 == 0):
            publisher.publish("RB3/ROBO3", "RB3XRETPUNE2")
            i2 = 0
            j2 = j2 + 1
            print('j2', j2)
            print('i2', i2)

    if (message == "RB3XDRPJAIPURI2"):
        print(message)
        while (j2 == 0):
            publisher.publish("RB3/ROBO3", "RB3XRETJAIPUR2")
            i2 = 0
            j2 = j2 + 1
            print('j2', j2)
            print('i2', i2)

    if (message == "RB3XDRPDELHII2"):
        print(message)
        while (j2 == 0):
            publisher.publish("RB3/ROBO3", "RB3XRETDELHI2")
            i2 = 0
            j2 = j2 + 1
            print('j2', j2)
            print('i2', i2)

    if (message == "RB3XDRPBENGI2"):
        print(message)
        while (j2 == 0):
            publisher.publish("RB3/ROBO3", "RB3XRETBENG2")
            i2 = 0
            j2 = j2 + 1
            print('j2', j2)
            print('i2', i2)

    if (message == "RB3XDRPHYDERI2"):
        print(message)
        while (j2 == 0):
            publisher.publish("RB3/ROBO3", "RB3XRETHYDER2")
            i2 = 0
            j2 = j2 + 1
            print('j2', j2)
            print('i2', i2)

    if (message == "RB3XDRPKOLKATAI2"):
        print(message)
        while (j2 == 0):
            publisher.publish("RB3/ROBO3", "RB3XRETKOLKATA2")
            i2 = 0
            j2 = j2 + 1
            print('j2', j2)
            print('i2', i2)

    if (message == "RB3XDRPCHENNAII2"):
        print(message)
        while (j2 == 0):
            publisher.publish("RB3/ROBO3", "RB3XRETCHENNAI2")
            i2 = 0
            j2 = j2 + 1
            print('j2', j2)
            print('i2', i2)
    # RB1 ARUCO 2
    if (message == "RB1XDRPABADI1"):
        print(message)
        while (j == 0):
            # print("loop")
            publisher.publish("RB1/ROBO1", "RB1XRETABAD1")
            j = j + 1
            i = 0
            print('j', j)
            print('i', i)
    if (message == "RB1XDRPMUMBAII1"):
        print(message)
        while (j == 0):
            publisher.publish("RB1/ROBO1", "RB1XRETMUMBAI1")
            j = j + 1
            i = 0
            print('j', j)
            print('i', i)

    if (message == "RB1XDRPPUNEI1"):
        print(message)
        while (j == 0):
            publisher.publish("RB1/ROBO1", "RB1XRETPUNE1")
            i = 0
            j = j + 1
            print('j', j)
            print('i', i)

    if (message == "RB1XDRPJAIPURI1"):
        print(message)
        while (j == 0):
            publisher.publish("RB1/ROBO1", "RB1XRETJAIPUR1")
            i = 0
            j = j + 1
            print('j', j)
            print('i', i)

    if (message == "RB1XDRPDELHII1"):
        print(message)
        while (j == 0):
            publisher.publish("RB1/ROBO1", "RB1XRETDELHI1")
            i = 0
            j = j + 1
            print('j', j)
            print('i', i)

    if (message == "RB1XDRPBENGI1"):
        print(message)
        while (j == 0):
            publisher.publish("RB1/ROBO1", "RB1XRETBENG1")
            i = 0
            j = j + 1
            print('j', j)
            print('i', i)

    if (message == "RB1XDRPHYDERI1"):
        print(message)
        while (j == 0):
            publisher.publish("RB1/ROBO1", "RB1XRETHYDER1")
            i = 0
            j = j + 1
            print('j', j)
            print('i', i)

    if (message == "RB1XDRPKOLKATAI1"):
        print(message)
        while (j == 0):
            publisher.publish("RB1/ROBO1", "RB1XRETKOLKATA1")
            i = 0
            j = j + 1
            print('j', j)
            print('i', i)

    if (message == "RB1XDRPCHENNAII1"):
        print(message)
        while (j == 0):
            publisher.publish("RB1/ROBO1", "RB1XRETCHENNAI1")
            i = 0
            j = j + 1
            print('j', j)
            print('i', i)

    # RB2 ARUCO 3
    if (message == "RB2XDRPABADI1"):
        print(message)
        while (j1 == 0):
            publisher.publish("RB2/ROBO2", "RB2XRETABAD1")
            i1 = 0
            j1 = j1 + 1
            print('j1', j1)
            print('i1', i1)

    if (message == "RB2XDRPMUMBAII1"):
        print(message)
        while (j1 == 0):
            publisher.publish("RB2/ROBO2", "RB2XRETMUMBAI1")
            i1 = 0
            j1 = j1 + 1
            print('j1', j1)
            print('i1', i1)

    if (message == "RB2XDRPPUNEI1"):
        print(message)
        while (j1 == 0):
            publisher.publish("RB2/ROBO2", "RB2XRETPUNE1")
            i1 = 0
            j1 = j1 + 1
            print('j1', j1)
            print('i1', i1)

    if (message == "RB2XDRPJAIPURI1"):
        print(message)
        while (j1 == 0):
            publisher.publish("RB2/ROBO2", "RB2XRETJAIPUR1")
            i1 = 0
            j1 = j1 + 1
            print('j1', j1)
            print('i1', i1)

    if (message == "RB2XDRPDELHII1"):
        print(message)
        while (j1 == 0):
            publisher.publish("RB2/ROBO2", "RB2XRETDELHI1")
            i1 = 0
            j1 = j1 + 1
            print('j1', j1)
            print('i1', i1)

    if (message == "RB2XDRPBENGI1"):
        print(message)
        while (j1 == 0):
            publisher.publish("RB2/ROBO2", "RB2XRETBENG1")
            i1 = 0
            j1 = j1 + 1
            print('j1', j1)
            print('i1', i1)

    if (message == "RB2XDRPHYDERI1"):
        print(message)
        while (j1 == 0):
            publisher.publish("RB2/ROBO2", "RB2XRETHYDER1")
            i1 = 0
            j1 = j1 + 1
            print('j1', j1)
            print('i1', i1)
    if (message == "RB2XDRPKOLKATAI1"):
        print(message)
        while (j1 == 0):
            publisher.publish("RB2/ROBO2", "RB2XRETKOLKATA1")
            i1 = 0
            j1 = j1 + 1
            print('j1', j1)
            print('i1', i1)

    if (message == "RB2XDRPCHENNAII1"):
        print(message)
        while (j1 == 0):
            publisher.publish("RB2/ROBO2", "RB2XRETCHENNAI1")
            i1 = 0
            j1 = j1 + 1
            print('j1', j1)
            print('i1', i1)

    # RB1 ARUCO 2
    # INDUCT 2
    if (message == "RB1XDRPABADI2"):
        print(message)
        while (j == 0):
            # print("loop")
            publisher.publish("RB1/ROBO1", "RB1XRETABAD2")
            j = j + 1
            i = 0
            print('j', j)
            print('i', i)

    if (message == "RB1XDRPMUMBAII2"):
        print(message)
        while (j == 0):
            publisher.publish("RB1/ROBO1", "RB1XRETMUMBAI2")
            j = j + 1
            i = 0
            print('j', j)
            print('i', i)

    if (message == "RB1XDRPPUNEI2"):
        print(message)
        while (j == 0):
            publisher.publish("RB1/ROBO1", "RB1XRETPUNE2")
            i = 0
            j = j + 1
            print('j', j)
            print('i', i)

    if (message == "RB1XDRPJAIPURI2"):
        print(message)
        while (j == 0):
            publisher.publish("RB1/ROBO1", "RB1XRETJAIPUR2")
            i = 0
            j = j + 1
            print('j', j)
            print('i', i)

    if (message == "RB1XDRPDELHII2"):
        print(message)
        while (j == 0):
            publisher.publish("RB1/ROBO1", "RB1XRETDELHI2")
            i = 0
            j = j + 1
            print('j', j)
            print('i', i)

    if (message == "RB1XDRPBENGI2"):
        print(message)
        while (j == 0):
            publisher.publish("RB1/ROBO1", "RB1XRETBENG2")
            i = 0
            j = j + 1
            print('j', j)
            print('i', i)

    if (message == "RB1XDRPHYDERI2"):
        print(message)
        while (j == 0):
            publisher.publish("RB1/ROBO1", "RB1XRETHYDER2")
            i = 0
            j = j + 1
            print('j', j)
            print('i', i)

    if (message == "RB1XDRPKOLKATAI2"):
        print(message)
        while (j == 0):
            publisher.publish("RB1/ROBO1", "RB1XRETKOLKATA2")
            i = 0
            j = j + 1
            print('j', j)
            print('i', i)

    if (message == "RB1XDRPCHENNAII2"):
        print(message)
        while (j == 0):
            publisher.publish("RB1/ROBO1", "RB1XRETCHENNAI2")
            i = 0
            j = j + 1
            print('j', j)
            print('i', i)

    # RB1 ARUCO 3
    if (message == "RB2XDRPABADI2"):
        print(message)
        while (j1 == 0):
            publisher.publish("RB2/ROBO2", "RB2XRETABAD2")
            i1 = 0
            j1 = j1 + 1
            print('j1', j1)
            print('i1', i1)

    if (message == "RB2XDRPMUMBAII2"):
        print(message)
        while (j1 == 0):
            publisher.publish("RB2/ROBO2", "RB2XRETMUMBAI2")
            i1 = 0
            j1 = j1 + 1
            print('j1', j1)
            print('i1', i1)

    if (message == "RB2XDRPPUNEI2"):
        print(message)
        while (j1 == 0):
            publisher.publish("RB2/ROBO2", "RB2XRETPUNE2")
            i1 = 0
            j1 = j1 + 1
            print('j1', j1)
            print('i1', i1)

    if (message == "RB2XDRPJAIPURI2"):
        print(message)
        while (j1 == 0):
            publisher.publish("RB2/ROBO2", "RB2XRETJAIPUR2")
            i1 = 0
            j1 = j1 + 1
            print('j1', j1)
            print('i1', i1)

    if (message == "RB2XDRPDELHII2"):
        print(message)
        while (j1 == 0):
            publisher.publish("RB2/ROBO2", "RB2XRETDELHI2")
            i1 = 0
            j1 = j1 + 1
            print('j1', j1)
            print('i1', i1)

    if (message == "RB2XDRPBENGI2"):
        print(message)
        while (j1 == 0):
            publisher.publish("RB2/ROBO2", "RB2XRETBENG2")
            i1 = 0
            j1 = j1 + 1
            print('j1', j1)
            print('i1', i1)

    if (message == "RB2XDRPHYDERI2"):
        print(message)
        while (j1 == 0):
            publisher.publish("RB2/ROBO2", "RB2XRETHYDER2")
            i1 = 0
            j1 = j1 + 1
            print('j1', j1)
            print('i1', i1)

    if (message == "RB2XDRPKOLKATAI2"):
        print(message)
        while (j1 == 0):
            publisher.publish("RB2/ROBO2", "RB2XRETKOLKATA2")
            i1 = 0
            j1 = j1 + 1
            print('j1', j1)
            print('i1', i1)

    if (message == "RB2XDRPCHENNAII2"):
        print(message)
        while (j1 == 0):
            publisher.publish("RB2/ROBO2", "RB2XRETCHENNAI2")
            i1 = 0
            j1 = j1 + 1
            print('j1', j1)
            print('i1', i1)


publisher = mqtt.Client("PYTHON")  # Create instance of client with client ID “digi_mqtt_test”
# publisher.on_connect = on_connect  # Define callback function for successful connection
# publisher.on_message = on_message  # Define callback function for receipt of a message

publisher.connect(broker, port)

path = 0
cx2, cy2 = 0, 0
cx3, cy3 = 0, 0
cx6, cy6 = 0, 0


ARUCO_DICT = {
    "DICT_4X4_50": cv2.aruco.DICT_4X4_50,
    "DICT_4X4_100": cv2.aruco.DICT_4X4_100,
    "DICT_4X4_250": cv2.aruco.DICT_4X4_250,
    "DICT_4X4_1000": cv2.aruco.DICT_4X4_1000,
    "DICT_5X5_50": cv2.aruco.DICT_5X5_50,
    "DICT_5X5_100": cv2.aruco.DICT_5X5_100,
    "DICT_5X5_250": cv2.aruco.DICT_5X5_250,
    "DICT_5X5_1000": cv2.aruco.DICT_5X5_1000,
    "DICT_6X6_50": cv2.aruco.DICT_6X6_50,
    "DICT_6X6_100": cv2.aruco.DICT_6X6_100,
    "DICT_6X6_250": cv2.aruco.DICT_6X6_250,
    "DICT_6X6_1000": cv2.aruco.DICT_6X6_1000,
    "DICT_7X7_50": cv2.aruco.DICT_7X7_50,
    "DICT_7X7_100": cv2.aruco.DICT_7X7_100,
    "DICT_7X7_250": cv2.aruco.DICT_7X7_250,
    "DICT_7X7_1000": cv2.aruco.DICT_7X7_1000,
    "DICT_ARUCO_ORIGINAL": cv2.aruco.DICT_ARUCO_ORIGINAL,
    "DICT_APRILTAG_16h5": cv2.aruco.DICT_APRILTAG_16h5,
    "DICT_APRILTAG_25h9": cv2.aruco.DICT_APRILTAG_25h9,
    "DICT_APRILTAG_36h10": cv2.aruco.DICT_APRILTAG_36h10,
    "DICT_APRILTAG_36h11": cv2.aruco.DICT_APRILTAG_36h11
}

CACHED_PTS = None
CACHED_PTS_2 = None
CACHED_PTS_3=None

CACHED_IDS = None
CACHED_IDS_2 = None
CACHED_IDS_3 = None


Line_Pts = None
measure = None
arucoParams = cv2.aruco.DetectorParameters_create()
arucoDict = cv2.aruco.Dictionary_get(cv2.aruco.DICT_4X4_250)

publisher.on_connect = on_connect
publisher.on_message = on_message
publisher.loop_start()

cap  = cv2.VideoCapture(1)
cap1 = cv2.VideoCapture(3)
cap2 = cv2.VideoCapture(0)
markerId_I1 = 0

markerId_I2 = 0
while True:

    Dist = []

    # Capture frame-by-frame
    ret0, frame0 = cap.read()
    ret1, frame1 = cap1.read()
    ret2, image = cap2.read()

    if (ret0):#for induct 1
        # Display the resulting frame
        #cv2.imshow('Cam 0', frame0)
        # Display the resulting frame
        Dist = []
        markerId_array = []
        # Display the resulting frame
        frame0 = imutils.resize(frame0, width=600)
        corners, ids, rejected = cv2.aruco.detectMarkers(frame0, arucoDict, parameters=arucoParams)
        if len(corners) <= 0:
            if CACHED_PTS is not None:
                corners = CACHED_PTS
        if len(corners) > 0:
            CACHED_PTS = corners
            if ids is not None:
                ids = ids.flatten()
                CACHED_IDS = ids
            else:
                if CACHED_IDS is not None:
                    ids = CACHED_IDS
            if len(corners) < 2:
                if len(CACHED_PTS) >= 2:
                    corners = CACHED_PTS
            for (markerCorner, markerId) in zip(corners, ids):
                # print("[INFO] Marker detected")
                corners_abcd = markerCorner.reshape((4, 2))
                (topLeft, topRight, bottomRight, bottomLeft) = corners_abcd
                topRightPoint = (int(topRight[0]), int(topRight[1]))
                topLeftPoint = (int(topLeft[0]), int(topLeft[1]))
                bottomRightPoint = (int(bottomRight[0]), int(bottomRight[1]))
                bottomLeftPoint = (int(bottomLeft[0]), int(bottomLeft[1]))
                cv2.line(frame0, topLeftPoint, topRightPoint, (0, 255, 0), 2)
                cv2.line(frame0, topRightPoint, bottomRightPoint, (0, 255, 0), 2)
                cv2.line(frame0, bottomRightPoint, bottomLeftPoint, (0, 255, 0), 2)
                cv2.line(frame0, bottomLeftPoint, topLeftPoint, (0, 255, 0), 2)
                cX = int((topLeft[0] + bottomRight[0]) // 2)
                cY = int((topLeft[1] + bottomRight[1]) // 2)

                # measure = abs(3.5 / (topLeft[0] - cX))
                # cv2.circle(frame0, (cX, cY), 4, (255, 0, 0), -1)
                cv2.putText(frame0, str(
                    int(markerId)), (int(topLeft[0] - 10), int(topLeft[1] - 10)), cv2.FONT_HERSHEY_COMPLEX, 1,
                            (0, 0, 255))
                # Dist.append((cX, cY))
                markerId_array.append(markerId)

                if 4 in markerId_array:
                    ind_2 = markerId_array.index(4)
                    markerId_I1 = markerId_array[ind_2]
                    # cx2, cy2 = Dist[ind_2]
                    # print("CX2,CY2:   ", cx2, cy2)

                if 8 in markerId_array:
                    ind_3 = markerId_array.index(8)
                    markerId_I1 = markerId_array[ind_3]
                    # cx3, cy3 = Dist[ind_3]

                if 6 in markerId_array:
                    ind_6 = markerId_array.index(6)
                    markerId_I1 = markerId_array[ind_6]

                for barcode in decode(frame0):
                    # print(barcode.data)
                    # print(barcode.rect)
                    myData = barcode.data.decode('utf-8')
                    print(myData)
                    pts = np.array([barcode.polygon], np.int32)
                    pts = pts.reshape((-1, 1, 2))
                    cv2.polylines(frame0, [pts], True, (255, 0, 255), 5)
                    pts2 = barcode.rect
                    cv2.putText(frame0, myData, (pts2[0], pts2[1]), cv2.FONT_HERSHEY_SIMPLEX, 0.9, (255, 0, 255), 2)

                    print(df[df['Shipment'] == myData])
                    comparison_values = df.values == myData
                    rows, cols = np.where(comparison_values == True)
                    city = df['Destination'][rows]
                    station1 = df['Induct Station'][rows]
                    station = str(station1)
                    print(station1)

                    if ("1.0" in station):
                        if ("Ahmedabad" in str(city)):
                            print("Ahmedabad")
                            city1 = "ABAD1"
                            print(i == 0)
                            if (i == 0 and markerId_I1 == 4):
                                print(city1)
                                publisher.publish("RB1/ROBO1", "RB1XI1ABAD")
                                i = i + 1
                                print("I:", i)
                                j = 0
                                print("J:", j)
                                k = 0
                                print("K:", k)
                            if (i1 == 0 and markerId_I1 == 8):
                                publisher.publish("RB2/ROBO2", "RB2XI1ABAD")
                                i1 = i1 + 1
                                print("I1:", i1)
                                j1 = 0
                                print("J1:", j1)
                                k1 = 0
                                print("K1:", k1)

                            if (i2 == 0 and markerId_I1 == 6):
                                publisher.publish("RB3/ROBO3", "RB3XI1ABAD")
                                i2 = i2 + 1
                                print("I2:", i2)
                                j2 = 0
                                print("J2:", j2)
                                k2 = 0
                                print("K2:", k2)

                        if ("Pune" in str(city)):
                            print("Pune")
                            city1 = "PUNE1"
                            print(i == 0)
                            if (i == 0 and markerId_I1 == 4):
                                print(city1)
                                publisher.publish("RB1/ROBO1", "RB1XI1PUNE")
                                i = i + 1
                                print("I:", i)
                                j = 0
                                print("J:", j)
                                k = 0
                                print("K:", k)
                            if (i1 == 0 and markerId_I1 == 8):
                                publisher.publish("RB2/ROBO2", "RB2XI1PUNE")
                                i1 = i1 + 1
                                print("I1:", i1)
                                j1 = 0
                                print("J1:", j1)
                                k1 = 0
                                print("K1:", k1)

                            if (i2 == 0 and markerId_I1 == 6):
                                publisher.publish("RB3/ROBO3", "RB3XI1PUNE")
                                i2 = i2 + 1
                                print("I2:", i2)
                                j2 = 0
                                print("J2:", j2)
                                k2 = 0
                                print("K2:", k2)

                        if ("Jaipur" in str(city)):
                            print("Jaipur")
                            city1 = "JAIPUR1"
                            print(i == 0)
                            if (i == 0 and markerId_I1 == 4):
                                print(city1)
                                publisher.publish("RB1/ROBO1", "RB1XI1JAIPUR")
                                i = i + 1
                                print("I:", i)
                                j = 0
                                print("J:", j)
                                k = 0
                                print("K:", k)
                            if (i1 == 0 and markerId_I1 == 8):
                                publisher.publish("RB2/ROBO2", "RB2XI1JAIPUR")
                                i1 = i1 + 1
                                print("I1:", i1)
                                j1 = 0
                                print("J1:", j1)
                                k1 = 0
                                print("K1:", k1)

                            if (i2 == 0 and markerId_I1 == 6):
                                publisher.publish("RB3/ROBO3", "RB3XI1JAIPUR")
                                i2 = i2 + 1
                                print("I2:", i2)
                                j2 = 0
                                print("J2:", j2)
                                k2 = 0
                                print("K2:", k2)

                        if ("Chennai" in str(city)):
                            print("Chennai")
                            city1 = "CHENNAI1"
                            print(i == 0)
                            if (i == 0 and markerId_I1 == 4):
                                print(city1)
                                publisher.publish("RB1/ROBO1", "RB1XI1CHENNAI")
                                i = i + 1
                                print("I:", i)
                                j = 0
                                print("J:", j)
                                k = 0
                                print("K:", k)
                            if (i1 == 0 and markerId_I1 == 8):
                                publisher.publish("RB2/ROBO2", "RB2XI1CHENNAI")
                                i1 = i1 + 1
                                print("I1:", i1)
                                j1 = 0
                                print("J1:", j1)
                                k1 = 0
                                print("K1:", k1)

                            if (i2 == 0 and markerId_I1 == 6):
                                publisher.publish("RB3/ROBO3", "RB3XI1CHENNAI")
                                i2 = i2 + 1
                                print("I2:", i2)
                                j2 = 0
                                print("J2:", j2)
                                k2 = 0
                                print("K2:", k2)

                        if ("Bengaluru" in str(city)):
                            print("Bengaluru")
                            city1 = "BENG1"
                            print(i == 0)
                            if (i == 0 and markerId_I1 == 4):
                                print(city1)
                                publisher.publish("RB1/ROBO1", "RB1XBENGI1")
                                i = i + 1
                                print("I:", i)
                                j = 0
                                print("J:", j)
                                k = 0
                                print("K:", k)
                            if (i1 == 0 and markerId_I1 == 8):
                                publisher.publish("RB2/ROBO2", "RB2XBENGI1")
                                i1 = i1 + 1
                                print("I1:", i1)
                                j1 = 0
                                print("J1:", j1)
                                k1 = 0
                                print("K1:", k1)

                            if (i2 == 0 and markerId_I1 == 6):
                                publisher.publish("RB3/ROBO3", "RB3XBENGI1")
                                i2 = i2 + 1
                                print("I2:", i2)
                                j2 = 0
                                print("J2:", j2)
                                k2 = 0
                                print("K2:", k2)

                        if ("Hyderabad" in str(city)):
                            print("Hyderabad")
                            city1 = "HYDER1"
                            print(i == 0)
                            if (i == 0 and markerId_I1 == 4):
                                print(city1)
                                publisher.publish("RB1/ROBO1", "RB1XI1HYDER")
                                i = i + 1
                                print("I:", i)
                                j = 0
                                print("J:", j)
                                k = 0
                                print("K:", k)
                            if (i1 == 0 and markerId_I1 == 8):
                                publisher.publish("RB2/ROBO2", "RB2XI1HYDER")
                                i1 = i1 + 1
                                print("I1:", i1)
                                j1 = 0
                                print("J1:", j1)
                                k1 = 0
                                print("K1:", k1)

                            if (i2 == 0 and markerId_I1 == 6):
                                publisher.publish("RB3/ROBO3", "RB3XI1HYDER")
                                i2 = i2 + 1
                                print("I2:", i2)
                                j2 = 0
                                print("J2:", j2)
                                k2 = 0
                                print("K2:", k2)

                        if ("Mumbai" in str(city)):
                            print("Mumbai")
                            city1 = "MUMBAI1"
                            print(i == 0)
                            if (i == 0 and markerId_I1 == 4):
                                print(city)
                                publisher.publish("RB1/ROBO1", "RB1XI1MUMBAI")
                                i = i + 1
                                print("I:", i)
                                j = 0
                                print("J:", j)
                                k = 0
                                print("K:", k)
                            if (i1 == 0 and markerId_I1 == 8):
                                publisher.publish("RB2/ROBO2", "RB2XI1MUMBAI")
                                i1 = i1 + 1
                                print("I1:", i1)
                                j1 = 0
                                print("J1:", j1)
                                k1 = 0
                                print("K1:", k1)

                            if (i2 == 0 and markerId_I1 == 6):
                                publisher.publish("RB3/ROBO3", "RB3XIMUMBAI")
                                i2 = i2 + 1
                                print("I2:", i2)
                                j2 = 0
                                print("J2:", j2)
                                k2 = 0
                                print("K2:", k2)

                        if ("Delhi" in str(city)):
                            print("Delhi")
                            city1 = "DELHI1"
                            print(i == 0)
                            if (i == 0 and markerId_I1 == 4):
                                print(city1)
                                publisher.publish("RB1/ROBO1", "RB1XI1DELHI")
                                i = i + 1
                                print("I:", i)
                                j = 0
                                print("J:", j)
                                k = 0
                                print("K:", k)
                            if (i1 == 0 and markerId_I1 == 8):
                                publisher.publish("RB2/ROBO2", "RB2XI1DELHI")
                                i1 = i1 + 1
                                print("I1:", i1)
                                j1 = 0
                                print("J1:", j1)
                                k1 = 0
                                print("K1:", k1)

                            if (i2 == 0 and markerId_I1 == 6):
                                publisher.publish("RB3/ROBO3", "RB3XI1DELHI")
                                i2 = i2 + 1
                                print("I2:", i2)
                                j2 = 0
                                print("J2:", j2)
                                k2 = 0
                                print("K2:", k2)

                        if ("Kolkata" in str(city)):
                            print("Kolkata")
                            city1 = "KOLKATA1"
                            print(i == 0)
                            if (i == 0 and markerId_I1 == 4):
                                print(city1)
                                publisher.publish("RB1/ROBO1", "RB1XI1KOLKATA")
                                i = i + 1
                                print("I:", i)
                                j = 0
                                print("J:", j)
                                k = 0
                                print("K:", k)
                            if (i1 == 0 and markerId_I1 == 8):
                                publisher.publish("RB2/ROBO2", "RB2XI1KOLKATA")
                                i1 = i1 + 1
                                print("I1:", i1)
                                j1 = 0
                                print("J1:", j1)
                                k1 = 0
                                print("K1:", k1)

                            if (i2 == 0 and markerId_I1 == 6):
                                publisher.publish("RB3/ROBO3", "RB3XI1KOLKATA")
                                i2 = i2 + 1
                                print("I2:", i2)
                                j2 = 0
                                print("J2:", j2)
                                k2 = 0
                                print("K2:", k2)
                    else:
                        print("Invalid station")

        cv2.imshow('INDUCT 1', frame0)
        cv2.waitKey(1)

    # *****************************************************************************************************************

    if (ret1):  # for induct 2
        # Display the resulting frame
        # cv2.imshow('Cam 0', frame0)
        # Display the resulting frame
        Dist = []
        markerId_arrayI2 = []
        # Display the resulting frame
        frame1 = imutils.resize(frame1, width=600)
        corners_2, ids_2, rejected_2 = cv2.aruco.detectMarkers(frame1, arucoDict, parameters=arucoParams)
        if len(corners_2) <= 0:
            if CACHED_PTS_2 is not None:
                corners_2 = CACHED_PTS_2
        if len(corners_2) > 0:
            CACHED_PTS_2 = corners_2
            if ids_2 is not None:
                ids_2 = ids_2.flatten()
                CACHED_IDS_2 = ids_2
            else:
                if CACHED_IDS_2 is not None:
                    ids_2 = CACHED_IDS_2
            if len(corners_2) < 2:
                if len(CACHED_PTS_2) >= 2:
                    corners_2 = CACHED_PTS_2
            for (markerCorner_2, markerId_b) in zip(corners_2, ids_2):
                # print("[INFO] Marker detected")
                corners_abcd_2 = markerCorner_2.reshape((4, 2))
                (topLeft_2, topRight_2, bottomRight_2, bottomLeft_2) = corners_abcd_2
                topRightPoint_2 = (int(topRight_2[0]), int(topRight_2[1]))
                topLeftPoint_2 = (int(topLeft_2[0]), int(topLeft_2[1]))
                bottomRightPoint_2 = (int(bottomRight_2[0]), int(bottomRight_2[1]))
                bottomLeftPoint_2 = (int(bottomLeft_2[0]), int(bottomLeft_2[1]))
                cv2.line(frame1, topLeftPoint_2, topRightPoint_2, (0, 255, 0), 2)
                cv2.line(frame1, topRightPoint_2, bottomRightPoint_2, (0, 255, 0), 2)
                cv2.line(frame1, bottomRightPoint_2, bottomLeftPoint_2, (0, 255, 0), 2)
                cv2.line(frame1, bottomLeftPoint_2, topLeftPoint_2, (0, 255, 0), 2)
                cX = int((topLeft_2[0] + bottomRight_2[0]) // 2)
                cY = int((topLeft_2[1] + bottomRight_2[1]) // 2)

                # measure = abs(3.5 / (topLeft[0] - cX))
                # cv2.circle(frame1, (cX, cY), 4, (255, 0, 0), -1)
                cv2.putText(frame1, str(
                    int(markerId_b)), (int(topLeft_2[0] - 10), int(topLeft_2[1] - 10)), cv2.FONT_HERSHEY_COMPLEX, 1,
                            (0, 0, 255))
                markerId_arrayI2.append(markerId_b)
                # Dist.append((cX, cY))

            if 4 in markerId_arrayI2:
                ind_2 = markerId_arrayI2.index(4)
                markerId_I2 = markerId_arrayI2[ind_2]
                # cx2, cy2 = Dist[ind_2]
                # print("CX2,CY2:   ", cx2, cy2)

            if 8 in markerId_arrayI2:
                ind_3 = markerId_arrayI2.index(8)
                markerId_I2 = markerId_arrayI2[ind_3]
                # cx3, cy3 = Dist[ind_3]

            if 6 in markerId_arrayI2:
                ind_6 = markerId_arrayI2.index(6)
                markerId_I2 = markerId_arrayI2[ind_6]

            for barcode in decode(frame1):
                # print(barcode.data)
                # print(barcode.rect)
                myData = barcode.data.decode('utf-8')
                print(myData)
                pts = np.array([barcode.polygon], np.int32)
                pts = pts.reshape((-1, 1, 2))
                cv2.polylines(frame1, [pts], True, (255, 0, 255), 5)
                pts2 = barcode.rect
                cv2.putText(frame1, myData, (pts2[0], pts2[1]), cv2.FONT_HERSHEY_SIMPLEX, 0.9,
                            (255, 0, 255), 2)

                print(df[df['Shipment'] == myData])
                comparison_values = df.values == myData
                rows, cols = np.where(comparison_values == True)
                city= df['Destination'][rows]
                station1 = df['Induct Station'][rows]
                station = str(station1)
                print(station1)

                if ("2.0" in station):
                    if ("Ahmedabad" in str(city)):
                        print("Ahmedabad")
                        city2 = "ABAD2"
                        print(i == 0)
                        if (i == 0 and markerId_I2 == 4):
                            print(city2)
                            publisher.publish("RB1/ROBO1", "RB1XI2ABAD")
                            i = i + 1
                            print("I:", i)
                            j = 0
                            print("J:", j)
                            k = 0
                            print("K:", k)
                        if (i1 == 0 and markerId_I2 == 8):
                            publisher.publish("RB2/ROBO2", "RB2XI2ABAD")
                            i1 = i1 + 1
                            print("I1:", i1)
                            j1 = 0
                            print("J1:", j1)
                            k1 = 0
                            print("K1:", k1)
                        if (i2 == 0 and markerId_I2 == 6):
                            publisher.publish("RB3/ROBO3", "RB3XI2ABAD")
                            i2 = i2 + 1
                            print("I2:", i2)
                            j2 = 0
                            print("J2:", j2)
                            k2 = 0
                            print("K2:", k2)
                    if ("Pune" in str(city)):
                        print("Pune")
                        city2 = "PUNE2"
                        print(i == 0)
                        if (i == 0 and markerId_I2 == 4):
                            print(city2)
                            publisher.publish("RB1/ROBO1", "RB1XI2PUNE")
                            i = i + 1
                            print("I:", i)
                            j = 0
                            print("J:", j)
                            k = 0
                            print("K:", k)
                        if (i1 == 0 and markerId_I2 == 8):
                            publisher.publish("RB2/ROBO2", "RB2XI2PUNE")
                            i1 = i1 + 1
                            print("PUNE2")
                            print("I1:", i1)
                            j1 = 0
                            print("J1:", j1)
                            k1 = 0
                            print("K1:", k1)
                        if (i2 == 0 and markerId_I2 == 6):
                            publisher.publish("RB3/ROBO3", "RB3XI2PUNE")
                            i2 = i2 + 1
                            print("PUNE2")
                            print("I2:", i2)
                            j2 = 0
                            print("J2:", j2)
                            k2 = 0
                            print("K2:", k2)

                    if ("Kolkata" in str(city)):
                        print("KOLKATA")
                        city2 = "KOLKATA2"
                        print(i == 0)
                        if (i == 0 and markerId_I2 == 4):
                            print(city2)
                            publisher.publish("RB1/ROBO1", "RB1XI2KOLKATA")
                            i = i + 1
                            print("I:", i)
                            j = 0
                            print("J:", j)
                            k = 0
                            print("K:", k)
                        if (i1 == 0 and markerId_I2 == 8):
                            publisher.publish("RB2/ROBO2", "RB2XI2KOLKATA")
                            i1 = i1 + 1
                            print("I1:", i1)
                            j1 = 0
                            print("J1:", j1)
                            k1 = 0
                            print("K1:", k1)
                        if (i2 == 0 and markerId_I2 == 6):
                            publisher.publish("RB3/ROBO3", "RB3XI2KOLKATA")
                            i2 = i2 + 1
                            print("I2:", i2)
                            j2 = 0
                            print("J2:", j2)
                            k2 = 0
                            print("K2:", k2)

                    if ("Jaipur" in str(city)):
                        print("Jaipur")
                        city2 = "JAIPUR2"
                        print(i == 0)
                        if (i == 0 and markerId_I2 == 4):
                            print(city2)
                            publisher.publish("RB1/ROBO1", "RB1XI2JAIPUR")
                            i = i + 1
                            print("I:", i)
                            j = 0
                            print("J:", j)
                            k = 0
                            print("K:", k)
                        if (i1 == 0 and markerId_I2 == 8):
                            publisher.publish("RB2/ROBO2", "RB2XI2JAIPUR")
                            i1 = i1 + 1
                            print("I1:", i1)
                            j1 = 0
                            print("J1:", j1)
                            k1 = 0
                            print("K1:", k1)
                        if (i2 == 0 and markerId_I2 == 6):
                            publisher.publish("RB3/ROBO3", "RB3XI2JAIPUR")
                            i2 = i2 + 1
                            print("I2:", i2)
                            j2 = 0
                            print("J2:", j2)
                            k2 = 0
                            print("K2:", k2)

                    if ("Chennai" in str(city)):
                        print("Chennai")
                        city2 = "CHENNAI2"
                        print(i == 0)
                        if (i == 0 and markerId_I2 == 4):
                            print(city2)
                            publisher.publish("RB1/ROBO1", "RB1XI2CHENNAI")
                            i = i + 1
                            print("I:", i)
                            j = 0
                            print("J:", j)
                            k = 0
                            print("K:", k)
                        if (i1 == 0 and markerId_I2 == 8):
                            publisher.publish("RB2/ROBO2", "RB2XI2CHENNAI")
                            i1 = i1 + 1
                            print("I1:", i1)
                            j1 = 0
                            print("J1:", j1)
                            k1 = 0
                            print("K1:", k1)
                        if (i2 == 0 and markerId_I2 == 6):
                            publisher.publish("RB3/ROBO3", "RB3XI2CHENNAI")
                            i2 = i2 + 1
                            print("I2:", i2)
                            j2 = 0
                            print("J2:", j2)
                            k2 = 0
                            print("K2:", k2)

                    if ("Bengaluru" in str(city)):
                        print("BENGLURU")
                        city2 = "BENG2"
                        print(i == 0)
                        if (i == 0 and markerId_I2 == 4):
                            print(city2)
                            publisher.publish("RB1/ROBO1", "RB1XI2BENG")
                            i = i + 1
                            print("I:", i)
                            j = 0
                            print("J:", j)
                            k = 0
                            print("K:", k)
                        if (i1 == 0 and markerId_I2 == 8):
                            publisher.publish("RB2/ROBO2", "RB2XI2BENG")
                            i1 = i1 + 1
                            print("I1:", i1)
                            j1 = 0
                            print("J1:", j1)
                            k1 = 0
                            print("K1:", k1)
                        if (i2 == 0 and markerId_I2 == 6):
                            publisher.publish("RB3/ROBO3", "RB3XI2BENG")
                            i2 = i2 + 1
                            print("I2:", i2)
                            j2 = 0
                            print("J2:", j2)
                            k2 = 0
                            print("K2:", k2)

                    if ("Hyderabad" in str(city)):
                        print("Hyderabad")
                        city2 = "HYDER2"
                        print(i == 0)
                        if (i == 0 and markerId_I2 == 4):
                            print(city)
                            publisher.publish("RB1/ROBO1", "RB1XI2HYDER")
                            i = i + 1
                            print("I:", i)
                            j = 0
                            print("J:", j)
                            k = 0
                            print("K:", k)
                        if (i1 == 0 and markerId_I2 == 8):
                            publisher.publish("RB2/ROBO2", "RB2XI2HYDER")
                            i1 = i1 + 1
                            print("I1:", i1)
                            j1 = 0
                            print("J1:", j1)
                            k1 = 0
                            print("K1:", k1)
                        if (i2 == 0 and markerId_I2 == 6):
                            publisher.publish("RB3/ROBO3", "RB3XI2HYDER")
                            i2 = i2 + 1
                            print("I2:", i2)
                            j2 = 0
                            print("J2:", j2)
                            k2 = 0
                            print("K2:", k2)

                    if ("Delhi" in str(city)):
                        print("Delhi")
                        city2 = "DELHI2"
                        print(i == 0)
                        if (i == 0 and markerId_I2 == 4):
                            print(city)
                            publisher.publish("RB1/ROBO1", "RB1XI2DELHI")
                            i = i + 1
                            print("I:", i)
                            j = 0
                            print("J:", j)
                            k = 0
                            print("K:", k)
                        if (i1 == 0 and markerId_I2 == 8):
                            publisher.publish("RB2/ROBO2", "RB2XI2DELHI")
                            i1 = i1 + 1
                            print("I1:", i1)
                            j1 = 0
                            print("J1:", j1)
                            k1 = 0
                            print("K1:", k1)

                        if (i2 == 0 and markerId_I2 == 6):
                            publisher.publish("RB3/ROBO3", "RB3XI2DELHI")
                            i2 = i2 + 1
                            print("I2:", i2)
                            j2 = 0
                            print("J2:", j2)
                            k2 = 0
                            print("K2:", k2)

                    if ("Mumbai" in str(city)):
                        print("Mumbai")
                        city2 = "MUMBAI2"
                        print(i == 0)
                        if (i == 0 and markerId_I2 == 4):
                            print(city)
                            publisher.publish("RB1/ROBO1", "RB1XI2MUMBAI")
                            i = i + 1
                            print("I:", i)
                            j = 0
                            print("J:", j)
                            k = 0
                            print("K:", k)
                        if (i1 == 0 and markerId_I2 == 8):
                            publisher.publish("RB2/ROBO2", "RB2XI2MUMBAI")
                            i1 = i1 + 1
                            print("I1:", i1)
                            j1 = 0
                            print("J1:", j1)
                            k1 = 0
                            print("K1:", k1)
                        if (i2 == 0 and markerId_I2 == 6):
                            publisher.publish("RB3/ROBO3", "RB3XI2MUMBAI")
                            i2 = i2 + 1
                            print("I2:", i2)
                            j2 = 0
                            print("J2:", j2)
                            k2 = 0
                            print("K2:", k2)
                else:
                        print("Invalid station")

        cv2.imshow('INDUCT 2', frame1)
        cv2.waitKey(1)
    if (ret2):

        Dist = []
        markerId_arrayI3 = []
        # publisher.loop_start()
        image = imutils.resize(image, width=800)
        corners_3, ids_3, rejected_3 = cv2.aruco.detectMarkers(image, arucoDict, parameters=arucoParams)
        if len(corners_3) <= 0:
            if CACHED_PTS_3 is not None:
                corners_3 = CACHED_PTS_3
        if len(corners_3) > 0:
            CACHED_PTS_3 = corners_3
            if ids_3 is not None:
                ids_3 = ids_3.flatten()
                CACHED_IDS_3 = ids_3
            else:
                if CACHED_IDS_3 is not None:
                    ids_3 = CACHED_IDS_3
            if len(corners_3) < 2:
                if len(CACHED_PTS_3) >= 2:
                    corners_3 = CACHED_PTS_3
            for (markerCorner_3, markerId_3) in zip(corners_3, ids_3):
                # print("[INFO] Marker detected")
                corners_abcd_3 = markerCorner_3.reshape((4, 2))
                (topLeft_3, topRight_3, bottomRight_3, bottomLeft_3) = corners_abcd_3
                topRightPoint_3 = (int(topRight_3[0]), int(topRight_3[1]))
                topLeftPoint_3 = (int(topLeft_3[0]), int(topLeft_3[1]))
                bottomRightPoint_3 = (int(bottomRight_3[0]), int(bottomRight_3[1]))
                bottomLeftPoint_3 = (int(bottomLeft_3[0]), int(bottomLeft_3[1]))
                cv2.line(image, topLeftPoint_3, topRightPoint_3, (0, 255, 0), 2)
                cv2.line(image, topRightPoint_3, bottomRightPoint_3, (0, 255, 0), 2)
                cv2.line(image, bottomRightPoint_3, bottomLeftPoint_3, (0, 255, 0), 2)
                cv2.line(image, bottomLeftPoint_3, topLeftPoint_3, (0, 255, 0), 2)
                cX = int((topLeft_3[0] + bottomRight_3[0]) // 2)
                cY = int((topLeft_3[1] + bottomRight_3[1]) // 2)

                # measure = abs(3.5 / (topLeft[0] - cX))
                cv2.circle(image, (cX, cY), 4, (255, 0, 0), -1)
                cv2.putText(image, str(
                    int(markerId_3)), (int(topLeft_3[0] - 10), int(topLeft_3[1] - 10)), cv2.FONT_HERSHEY_COMPLEX, 0.2,
                            (0, 0, 255))
                Dist.append((cX, cY))
                markerId_arrayI3.append(markerId_3)

                aruco_centroid_3 = (cX, cY)
                cv2.putText(image, str(aruco_centroid_3), (int(topLeft_3[0] - 10), int(topLeft_3[1] - 10)),
                            cv2.FONT_HERSHEY_TRIPLEX, 0.5,
                            (255, 255, 255))

            # static coordinate aruco
            if 4 in markerId_arrayI3:
                ind_2 = markerId_arrayI3.index(4)
                cx2, cy2 = Dist[ind_2]
            # print("CX2,CY2:   ", cx2, cy2)

            if 5 in markerId_arrayI3:
                ind_3 = markerId_arrayI3.index(5)
                cx3, cy3 = Dist[ind_3]

            if 6 in markerId_arrayI3:
                ind_6 = markerId_arrayI3.index(6)
                cx6, cy6 = Dist[ind_6]
                # centroid_3=(cx3,cy3)
            # print("CX3,CY3:   ", cx3, cy3)

        # DROPPING CENTROIDS
        # cv2.putText(image, 'DROP', (185, 43), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 150), 2)
        # cv2.putText(image, str(centroid_3), (cx3 - 2, cy3 - 5), cv2.FONT_HERSHEY_SIMPLEX, 0.15, (255, 255, 255))
        imgray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
        ret, thresh = cv2.threshold(imgray, 150, 255, 0)
        contours, hierarchy = cv2.findContours(thresh, cv2.RETR_TREE, cv2.CHAIN_APPROX_NONE)
        # print('Number of contours = ' + str(len(contours)))
        for c in contours:
            area = cv2.contourArea(c)
            if area > 100:
                cv2.drawContours(image, [c], -1, (255, 0, 0), 1)

                M = cv2.moments(c)
                if M["m00"] != 0:
                    cx = int(M["m10"] / M["m00"])
                    cy = int(M["m01"] / M["m00"])
                else:
                    cx, cy = 0, 0

                centroid = (cx, cy)
                cv2.circle(image, (cx, cy), 2, (0, 0, 255), 2)
                # cv2.putText(image, str(centroid), (cx - 2, cy - 5), cv2.FONT_HERSHEY_SIMPLEX, 0.15, (255, 255, 255))
        # INDUCT 1
        # RB2
        if (cx3 < 389 and cy3 < 60) and (cx3 > 349 and cy3 > 43) and city1 == "ABAD1":
            print("Stop_Servo_Abad")
            while (k1 == 0):
                publisher.publish("RB2/ROBO2", "RB2XDROPPEDABADI1")
                k1 = k1 + 1
        if (cx3< 542 and cy3 < 146) and (cx3 > 500 and cy3 > 106) and city1 == "PUNE1":
            print("Stop_Servo_Pune")
            while (k1 == 0):
                publisher.publish("RB2/ROBO2", "RB2XDROPPEDPUNEI1")
                k1 = k1 + 1
        if (cx3 < 467 and cy3 < 353) and (cx3 > 449 and cy3 > 333) and city1 == "DELHI1":
            print("Stop_Servo_Delhi")
            while (k1 == 0):
                publisher.publish("RB2/ROBO2", "RB2XDROPPEDDELHII1")
                k1 = k1 + 1
        if (cx3 < 550 and cy3 < 290) and (cx3 > 510 and cy3 > 260) and city1 == "MUMBAI1":
            print("Stop_Servo_Mumbai")
            while (k1 == 0):
                publisher.publish("RB2/ROBO2", "RB2XDROPPEDMUMBAII1")
                k1 = k1 + 1
        if (cx3 < 541 and cy3 < 252) and (cx3 > 521 and cy3 > 232) and city1 == "CHENNAI1":
            print("Stop_Servo_Chennai")
            while (k1 == 0):
                publisher.publish("RB2/ROBO2", "RB2XDROPPEDCHENNAII1")
                k1 = k1 + 1
        if (cx3 < 400 and cy3 < 83) and (cx3 > 249 and cy3 > 30) and city1 == "JAIPUR1":
            print("Stop_Servo_Jaipur")
            while (k1 == 0):
                publisher.publish("RB2/ROBO2", "RB2XDROPPEDJAIPURI1")
                k1 = k1 + 1
        if (cx3 < 550 and cy3 < 258) and (cx3 > 515 and cy3 > 215) and city1 == "KOLKATA1":
            print("Stop_Servo_Kolkata")
            while (k1 == 0):
                publisher.publish("RB2/ROBO2", "RB2XDROPPEDKOLKATAI1")
                k1 = k1 + 1
        if (cx3 < 347 and cy3 < 186) and (cx3 > 307 and cy3 > 146) and city1 == "HYDER1":
            print("Stop_Servo_Hyder")
            while (k1 == 0):
                publisher.publish("RB2/ROBO2", "RB2XDROPPEDHYDERI1")
                k1 = k1 + 1
        if (cx3 < 480 and cy3 < 189) and (cx3 > 449 and cy3 > 140) and city1 == "BENG1":
            print("Stop_Servo_Beng")
            while (k1 == 0):
                publisher.publish("RB2/ROBO2", "RB2XDROPPEDBENGI1")
                k1 = k1 + 1
        # RB1
        # print("CITY:",city)
        # print("MUM1: ",city == "DELHI1")
        # print("coordinate: ",(cx2 < 550 and cy2 < 290) and (cx2 > 510 and cy2 > 260))
        if (cx2 < 389 and cy2 < 60) and (cx2 > 349 and cy2 > 43) and city1 == "ABAD1":
            print("Stop_Servo_Abad")
            while (k == 0):
                publisher.publish("RB1/ROBO1", "RB1XDROPPEDABADI1")
                k = k + 1
        if (cx2 < 542 and cy2 < 146) and (cx2 > 500 and cy2 > 106) and city1 == "PUNE1":
            print("Stop_Servo_Pune")
            while (k == 0):
                publisher.publish("RB1/ROBO1", "RB1XDROPPEDPUNEI1")
                k = k + 1
        if (cx2 < 467 and cy2 < 353) and (cx2 > 449 and cy2 > 333) and city1 == "DELHI1":
            print("Stop_Servo_Delhi")
            while (k == 0):
                publisher.publish("RB1/ROBO1", "RB1XDROPPEDDELHII1")
                k = k + 1
        if (cx2 < 550 and cy2 < 290) and (cx2 > 510 and cy2 > 260)and city1 == "MUMBAI1":
            print("Stop_Servo_Mumbai")
            while (k == 0):
                publisher.publish("RB1/ROBO1", "RB1XDROPPEDMUMBAII1")
                k = k + 1
        if (cx2 < 541 and cy2 < 252) and (cx2 > 521 and cy2 > 232) and city1 == "CHENNAI1":
            print("Stop_Servo_Chennai")
            while (k == 0):
                publisher.publish("RB1/ROBO1", "RB1XDROPPEDCHENNAII1")
                k = k + 1
        if (cx2 < 400 and cy2 < 83) and (cx2 > 249 and cy2 > 30) and city1 == "JAIPUR1":
            print("Stop_Servo_Jaipur")
            while (k == 0):
                publisher.publish("RB1/ROBO1", "RB1XDROPPEDJAIPURI1")
                k = k + 1
        if (cx2 < 550 and cy2 < 258) and (cx2 > 515 and cy2 > 215) and city1 == "KOLKATA1":
            print("Stop_Servo_Kolkata")
            while (k == 0):
                publisher.publish("RB1/ROBO1", "RB1XDROPPEDKOLKATAI1")
                k = k + 1
        if (cx2 < 347 and cy2 < 186) and (cx2 > 307 and cy2 > 146) and city1 == "HYDER1":
            print("Stop_Servo_Hyder")
            while (k == 0):
                publisher.publish("RB1/ROBO1", "RB1XDROPPEDHYDERI1")
                k = k + 1
        if (cx2 < 480 and cy2 < 189) and (cx2 > 449 and cy2 > 140) and city1 == "BENG1":
            print("Stop_Servo_Beng")
            while (k == 0):
                publisher.publish("RB1/ROBO1", "RB1XDROPPEDBENGI1")
                k = k + 1
        #RB3
        if (cx6 < 389 and cy6 < 60) and (cx6 > 349 and cy6 > 43) and city1 == "ABAD1":
            print("Stop_Servo_Abad")
            while (k2 == 0):
                publisher.publish("RB3/ROBO3", "RB3XDROPPEDABADI1")
                k2 = k2 + 1
        if (cx6< 542 and cy6 < 146) and (cx6 > 500 and cy6 > 106) and city1 == "PUNE1":
            print("Stop_Servo_Pune")
            while (k2 == 0):
                publisher.publish("RB3/ROBO3", "RB3XDROPPEDPUNEI1")
                k2 = k2 + 1
        if (cx6 < 467 and cy6 < 353) and (cx6 > 449 and cy6 > 333) and city1 == "DELHI1":
            print("Stop_Servo_Delhi")
            while (k2 == 0):
                publisher.publish("RB3/ROBO3", "RB3XDROPPEDDELHII1")
                k2 = k2 + 1
        if (cx6 < 550 and cy6 < 290) and (cx6 > 510 and cy6 > 260) and city1 == "MUMBAI1":
            print("Stop_Servo_Mumbai")
            while (k2 == 0):
                publisher.publish("RB3/ROBO3", "RB3XDROPPEDMUMBAII1")
                k2 = k2 + 1
        if (cx6 < 541 and cy6 < 252) and (cx6 > 521 and cy6 > 232) and city1 == "CHENNAI1":
            print("Stop_Servo_Chennai")
            while (k2 == 0):
                publisher.publish("RB3/ROBO3", "RB3XDROPPEDCHENNAII1")
                k2 = k2 + 1
        if (cx6 < 400 and cy6 < 83) and (cx6 > 249 and cy6 > 30) and city1 == "JAIPUR1":
            print("Stop_Servo_Jaipur")
            while (k2 == 0):
                publisher.publish("RB3/ROBO3", "RB3XDROPPEDJAIPURI1")
                k2 = k2 + 1
        if (cx6 < 550 and cy6 < 258) and (cx6 > 515 and cy6 > 215) and city1 == "KOLKATA1":
            print("Stop_Servo_Kolkata")
            while (k2 == 0):
                publisher.publish("RB3/ROBO3", "RB3XDROPPEDKOLKATAI1")
                k2 = k2 + 1
        if (cx6 < 347 and cy6 < 186) and (cx6 > 307 and cy6 > 146) and city1 == "HYDER1":
            print("Stop_Servo_Hyder")
            while (k2 == 0):
                publisher.publish("RB3/ROBO3", "RB3XDROPPEDHYDERI1")
                k2 = k2 + 1
        if (cx6 < 480 and cy6 < 189) and (cx6 > 449 and cy6 > 140) and city1 == "BENG1":
            print("Stop_Servo_Beng")
            while (k2 == 0):
                publisher.publish("RB3/ROBO3", "RB3XDROPPEDBENGI1")
                k2 = k2 + 1

        # INDUCT 2
        # RB1
        if (cx2 < 470 and cy2 < 78) and (cx2 > 450 and cy2 > 56) and city2 == "ABAD2":
            print("Stop_Servo_Abad_2")
            while (k == 0):
                publisher.publish("RB1/ROBO1", "RB1XDROPPEDABADI2")
                k = k + 1
        if (cx2 < 542 and cy2 < 111) and (cx2 > 522 and cy2 > 91) and city2 == "PUNE2":
            print("Stop_Servo_Pune2")
            while (k == 0):
                publisher.publish("RB1/ROBO1", "RB1XDROPPEDPUNEI2")
                k = k + 1
        if (cx2 < 368 and cy2 < 291) and (cx2 > 348 and cy2 > 271) and city2 == "DELHI2":
            print("Stop_Servo_Delhi2")
            while (k == 0):
                publisher.publish("RB1/ROBO1", "RB1XDROPPEDDELHII2")
                k = k + 1
        if (cx2 < 542 and cy2 < 273) and (cx2 > 522 and cy2 > 253) and city2 == "MUMBAI2":
            print("Stop_Servo_Mumbai2")
            while (k == 0):
                publisher.publish("RB1/ROBO1", "RB1XDROPPEDMUMBAII2")
                k = k + 1
        if (cx2 < 610 and cy2 < 220) and (cx2 > 590 and cy2 > 200) and city2 == "CHENNAI2":
            print("Stop_Servo_Chennai2")
            while (k == 0):
                publisher.publish("RB1/ROBO1", "RB1XDROPPEDCHENNAII2")
                k = k + 1
        if (cx2 < 342 and cy2 < 73) and (cx2 > 322 and cy2 > 53) and city2 == "JAIPUR2":
            print("Stop_Servo_Jaipur2")
            while (k == 0):
                publisher.publish("RB1/ROBO1", "RB1XDROPPEDJAIPURI2")
                k = k + 1
        if (cx2 < 216 and cy2 < 328) and (cx2 > 196 and cy2 > 308) and city2 == "KOLKATA2":
            print("Stop_Servo_Kolkata2")
            while (k == 0):
                publisher.publish("RB1/ROBO1", "RB1XDROPPEDKOLKATAI2")
                k = k + 1
        if (cx2 < 232 and cy2 < 192) and (cx2 > 212 and cy2 > 172) and city2 == "HYDER2":
            print("Stop_Servo_Hyder2")
            while (k == 0):
                publisher.publish("RB1/ROBO1", "RB1XDROPPEDHYDERI2")
                k = k + 1
        if (cx2 < 365 and cy2 < 179) and (cx2 > 345 and cy2 > 159) and city2 == "BENG2":
            print("Stop_Servo_Beng2")
            while (k == 0):
                publisher.publish("RB1/ROBO1", "RB1XDROPPEDBENGI2")
                k = k + 1
        #RB2
        if (cx3 < 470 and cy3 < 78) and (cx3 > 450 and cy3 > 56) and city2 == "ABAD2":
            print("Stop_Servo_Abad_2")
            while (k1 == 0):
                publisher.publish("RB2/ROBO2", "RB2XDROPPEDABADI2")
                k1 = k1 + 1
        if (cx3 < 542 and cy3 < 111) and (cx3 > 522 and cy3 > 91) and city2 == "PUNE2":
            print("Stop_Servo_Pune_2")
            while (k1 == 0):
                publisher.publish("RB2/ROBO2", "RB2XDROPPEDPUNEI2")
                k1 = k1 + 1
        if (cx3 < 368 and cy3 < 291) and (cx3 > 348 and cy3 > 271) and city2 == "DELHI2":
            print("Stop_Servo_Delhi_2")
            while (k1 == 0):
                publisher.publish("RB2/ROBO2", "RB2XDROPPEDDELHII2")
                k1 = k1 + 1
        if (cx3 < 542 and cy3 < 273) and (cx3 > 522 and cy3 > 253) and city2 == "MUMBAI2":
            print("Stop_Servo_Mumbai_2")
            while (k1 == 0):
                publisher.publish("RB2/ROBO2", "RB2XDROPPEDMUMBAII2")
                k1 = k1 + 1
        if (cx3 < 610 and cy3 < 220) and (cx3 > 590 and cy3 > 200) and city2 == "CHENNAI2":
            print("Stop_Servo_Chennai_2")
            while (k1 == 0):
                publisher.publish("RB2/ROBO2", "RB2XDROPPEDCHENNAII2")
                k1 = k1 + 1
        if (cx3 < 342 and cy3 < 73) and (cx3 > 322 and cy3 > 53) and city2 == "JAIPUR2":
            print("Stop_Servo_Jaipur_2")
            while (k1 == 0):
                publisher.publish("RB2/ROBO2", "RB2XDROPPEDJAIPURI2")
                k1 = k1 + 1
        if (cx3 < 216 and cy3 < 328) and (cx3 > 196 and cy3 > 308) and city2 == "KOLKATA2":
            print("Stop_Servo_Kolkata_2")
            while (k1 == 0):
                publisher.publish("RB2/ROBO2", "RB2XDROPPEDKOLKATAI2")
                k1 = k1 + 1
        if (cx3 < 232 and cy3 < 192) and (cx3 > 212 and cy3 > 172) and city2 == "HYDER2":
            print("Stop_Servo_Hyder_2")
            while (k1 == 0):
                publisher.publish("RB2/ROBO2", "RB2XDROPPEDHYDERI2")
                k1 = k1 + 1
        if (cx3 < 365 and cy3 < 179) and (cx3 > 345 and cy3 > 159) and city2 == "BENG2":
            print("Stop_Servo_Beng_2")
            while (k1 == 0):
                publisher.publish("RB2/ROBO2", "RB2XDROPPEDBENGI2")
                k1 = k1 + 1
        # RB3
        if (cx6 < 470 and cy6 < 78) and (cx6 > 450 and cy6 > 56) and city2 == "ABAD2":
            print("Stop_Servo_Abad_2")
            while (k2 == 0):
                publisher.publish("RB3/ROBO3", "RB3XDROPPEDABADI2")
                k2 = k2 + 1
        if (cx6 < 542 and cy6 < 111) and (cx6 > 522 and cy6 > 91) and city2 == "PUNE2":
            print("Stop_Servo_Pune2")
            while (k2 == 0):
                publisher.publish("RB3/ROBO3", "RB3XDROPPEDPUNEI2")
                k2 = k2 + 1
        if (cx6 < 368 and cy6 < 291) and (cx6 > 348 and cy6 > 271) and city2 == "DELHI2":
            print("Stop_Servo_Delhi2")
            while (k2 == 0):
                publisher.publish("RB3/ROBO3", "RB3XDROPPEDDELHII2")
                k2 = k2 + 1
        if (cx6 < 542 and cy6 < 273) and (cx6 > 522 and cy6 > 253) and city2 == "MUMBAI2":
            print("Stop_Servo_Mumbai2")
            while (k2 == 0):
                publisher.publish("RB3/ROBO3", "RB3XDROPPEDMUMBAII2")
                k2 = k2 + 1
        if (cx6 < 610 and cy6 < 220) and (cx6 > 590 and cy6 > 200) and city2 == "CHENNAI2":
            print("Stop_Servo_Chennai2")
            while (k2 == 0):
                publisher.publish("RB3/ROBO3", "RB3XDROPPEDCHENNAII2")
                k2 = k2 + 1
        if (cx6 < 342 and cy6 < 73) and (cx6 > 322 and cy6 > 53) and city2 == "JAIPUR2":
            print("Stop_Servo_Jaipur2")
            while (k2 == 0):
                publisher.publish("RB3/ROBO3", "RB3XDROPPEDJAIPURI2")
                k2 = k2 + 1
        if (cx6 < 216 and cy6 < 328) and (cx6 > 196 and cy6 > 308) and city2 == "KOLKATA2":
            print("Stop_Servo_Kolkata2")
            while (k2 == 0):
                publisher.publish("RB3/ROBO3", "RB3XDROPPEDKOLKATAI2")
                k2 = k2 + 1
        if (cx6 < 232 and cy6 < 192) and (cx6 > 212 and cy6 > 172) and city2 == "HYDER2":
            print("Stop_Servo_Hyder2")
            while (k2 == 0):
                publisher.publish("RB3/ROBO3", "RB3XDROPPEDHYDERI2")
                k2 = k2 + 1
        if (cx6 < 365 and cy6 < 179) and (cx6 > 345 and cy6 > 159) and city2 == "BENG2":
            print("Stop_Servo_Beng2")
            while (k2 == 0):
                publisher.publish("RB3/ROBO3", "RB3XDROPPEDBENGI2")
                k2 = k2 + 1
        cv2.imshow('ARENA CAM 1', image)
        cv2.waitKey(1)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        cv2.destroyAllWindows()
        break

# When everything is done, release the capture
cap.release()
cap1.release()
cap2.release()

cv2.destroyAllWindows()
publisher.loop_stop()