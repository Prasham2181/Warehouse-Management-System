# This code is developed under the title autonomous warehouse management system
# Image Processing code of the system
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
import paho.mqtt.client as mqtt

cap  = cv2.VideoCapture(0)
cap1 = cv2.VideoCapture(1)
cap2 = cv2.VideoCapture(2)

message = ""
city = ""
broker= "192.168.1.101"
port = 2222
markerId = 0

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
# arucoDict = cv2.aruco.Dictionary_get(ARUCO_DICT[args['type']])
# arucoParams = cv2.aruco.DetectorParameters_create()


CACHED_PTS = None
CACHED_IDS = None
Line_Pts = None
measure = None
arucoParams = cv2.aruco.DetectorParameters_create()
arucoDict = cv2.aruco.Dictionary_get(cv2.aruco.DICT_5X5_100)
cx2,cy2=0,0
cx3,cy3=0,0
cx4,cy4=0,0
cx5,cy5=0,0
cx6,cy6=0,0
cx7,cy7=0,0
cx8,cy8=0,0
cx9,cy9=0,0
cx10,cy10=0,0
cx11,cy11=0,0
cx12,cy12=0,0
i=0

df = pd.read_excel('Sample Data.xlsx')

def on_connect(publisher, userdata, flags, rc):  # The callback for when the client connects to the broker
    print("Connected with result code {0}".format(str(rc)))  # Print result of connection attempt
    publisher.subscribe("PYTHON/PUBLISH")  # Subscribe to the topic “digitest/test1”, receive any messages published on it


def on_message(publisher, userdata, msg):  # The callback for when a PUBLISH message is received from the server.
    message = str(msg.payload.decode("utf-8"))
    print("Message received: ",message)  # Print a received msg
    if (message == "C_ABAD1_AVOID"):
        print(message)
        publisher.publish("RB2/ROBO2", "RB2XRET1ABD")

    if (message == "C_MUMBAI1_AVOID"):
        print(message)
        publisher.publish("RB2/ROBO2", "RB2XRET1MUMBAI")

    if (message == "C_PUNE1_AVOID"):
        print(message)
        publisher.publish("RB2/ROBO2", "RB2XRET1PUNE")

    if (message == "C_JAIPUR1_AVOID"):
        print(message)
        publisher.publish("RB2/ROBO2", "RB2XRET1JAIPUR")

    if (message == "C_DELHI1_AVOID"):
        print(message)
        publisher.publish("RB2/ROBO2", "RB2XRET1DELHI")

    if (message == "C_BENG1_AVOID"):
        print(message)
        publisher.publish("RB2/ROBO2", "RB2XRET1BENG")

    if (message == "C_HYDER1_AVOID"):
        print(message)
        publisher.publish("RB2/ROBO2", "RB2XRET1HYDER")

    if (message == "C_KOLKATA1_AVOID"):
        print(message)
        publisher.publish("RB2/ROBO2", "RB2XRET1KOLKATA")

    if (message == "C_CHENNAI1_AVOID"):
        print(message)
        publisher.publish("RB2/ROBO2", "RB2XRET1CHENNAI")

    # INDUCT 2
    if (message == "C_ABAD2_AVOID"):
        print(message)
        publisher.publish("RB2/ROBO2", "RB2XRET2ABD")

    if (message == "C_MUMBAI2_AVOID"):
        print(message)
        publisher.publish("RB2/ROBO2", "RB2XRET2MUMBAI")

    if (message == "C_PUNE2_AVOID"):
        print(message)
        publisher.publish("RB2/ROBO2", "RB2XRET2PUNE")

    if (message == "C_JAIPUR2_AVOID"):
        print(message)
        publisher.publish("RB2/ROBO2", "RB2XRET2JAIPUR")

    if (message == "C_DELHI2_AVOID"):
        print(message)
        publisher.publish("RB2/ROBO2", "RB2XRET2DELHI")

    if (message == "C_BENG2_AVOID"):
        print(message)
        publisher.publish("RB2/ROBO2", "RB2XRET2BENG")

    if (message == "C_HYDER2_AVOID"):
        print(message)
        publisher.publish("RB2/ROBO2", "RB2XRET2HYDER")

    if (message == "C_KOLKATA2_AVOID"):
        print(message)
        publisher.publish("RB2/ROBO2", "RB2XRET2KOLKATA")

    if (message == "C_CHENNAI2_AVOID"):
        print(message)
        publisher.publish("RB2/ROBO2", "RB2XRET2CHENNAI")

    # RB2 ARUCO 2
    if (message == "RB2XDRPABADI1"):
        print(message)
        publisher.publish("RB2/ROBO2", "RB2XRET2ABD")
        i=0

    if (message == "RB2XDRPMUMBAII1"):
        print(message)
        publisher.publish("RB2/ROBO2", "RB2XRET2MUMBAI")

    if (message == "RB2XDRPPUNEI1"):
        print(message)
        publisher.publish("RB2/ROBO2", "RB2XRET2PUNE")

    if (message == "RB2XDRPJAIPURI1"):
        print(message)
        publisher.publish("RB2/ROBO2", "RB2XRET2JAIPUR")

    if (message == "RB2XDRPDELHII1"):
        print(message)
        publisher.publish("RB2/ROBO2", "RB2XRET2DELHI")

    if (message == "RB2XDRPBENGI1"):
        print(message)
        publisher.publish("RB2/ROBO2", "RB2XRET2BENG")

    if (message == "RB2XDRPHYDERI1"):
        print(message)
        publisher.publish("RB2/ROBO2", "RB2XRET2HYDER")

    if (message == "RB2XDRPKOLKATAI1"):
        print(message)
        publisher.publish("RB2/ROBO2", "RB2XRET2KOLKATA")

    if (message == "RB2XDRPCHENNAII1"):
        print(message)
        publisher.publish("RB2/ROBO2", "RB2XRET2CHENNAI")


publisher = mqtt.Client("PYTHON")  # Create instance of client with client ID “digi_mqtt_test”
publisher.connect(broker, port)
publisher.on_connect = on_connect
publisher.on_message = on_message
publisher.loop_start()

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
        # Display the resulting frame
        frame0 = imutils.resize(frame0, width=800)
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

                measure = abs(3.5 / (topLeft[0] - cX))
                cv2.circle(frame0, (cX, cY), 4, (255, 0, 0), -1)
                cv2.putText(frame0, str(
                    int(markerId)), (int(topLeft[0] - 10), int(topLeft[1] - 10)), cv2.FONT_HERSHEY_COMPLEX, 1,
                            (0, 0, 255))
                Dist.append((cX, cY))

            if(markerId==2):
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
                            city = "ABAD"
                            publisher.publish("RB1/ROBO1","RB1XI1ABAD")
                        if ("Pune" in str(city)):
                            print("Pune")
                            city = "PUNE"
                            publisher.publish("RB1/ROBO1", "RB1XI1PUNE")
                        if ("Mumbai" in str(city)):
                            print("Mumbai")
                            city = "MUMBAI"
                            publisher.publish("RB1/ROBO1", "RB1XI1MUMBAI")
                        if ("Delhi" in str(city)):
                            print("Delhi")
                            city = "DELHI"
                            publisher.publish("RB1/ROBO1", "RB1XI1DELHI")
                        if ("Kolkata" in str(city)):
                            print("Kolkata")
                            city = "KOLKATA"
                            publisher.publish("RB1/ROBO1", "RB1XI1KOLKATA")
                        if ("Chennai" in str(city)):
                            print("Chennai")
                            city = "CHENNAI"
                            publisher.publish("RB1/ROBO1", "RB1XI1CHENNAI")
                        if ("Bengaluru" in str(city)):
                            print("Bengaluru")
                            city = "BENG"
                            publisher.publish("RB1/ROBO1", "RB1XI1BENG")
                        if ("Jaipur" in str(city)):
                            print("Jaipur")
                            city = "JAIPUR"
                            publisher.publish("RB1/ROBO1", "RB1XI1JAIPUR")
                        if ("Hyderabad" in str(city)):
                            print("Hyderabad")
                            city = "HYDER"
                            publisher.publish("RB1/ROBO1", "RB1XI1HYDER")
                    else:
                        print("Invalid station")

            if (markerId == 3):
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
                            city = "ABAD"
                            publisher.publish("RB2/ROBO2", "RB2XI1ABAD")
                        if ("Pune" in str(city)):
                            print("Pune")
                            city = "PUNE"
                            publisher.publish("RB2/ROBO2", "RB2XI1PUNE")
                        if ("Mumbai" in str(city)):
                            print("Mumbai")
                            city = "MUMBAI"
                            publisher.publish("RB2/ROBO2", "RB2XI1MUMBAI")
                        if ("Delhi" in str(city)):
                            print("Delhi")
                            city = "DELHI"
                            publisher.publish("RB2/ROBO2", "RB2XI1DELHI")
                        if ("Kolkata" in str(city)):
                            print("Kolkata")
                            city = "KOLKATA"
                            publisher.publish("RB2/ROBO2", "RB2XI1KOLKATA")
                        if ("Chennai" in str(city)):
                            print("Chennai")
                            city = "CHENNAI"
                            publisher.publish("RB2/ROBO2", "RB2XI1CHENNAI")
                        if ("Bengaluru" in str(city)):
                            print("Bengaluru")
                            city = "BENG"
                            publisher.publish("RB2/ROBO2", "RB2XI1BENG")
                        if ("Jaipur" in str(city)):
                            print("Jaipur")
                            city = "JAIPUR"
                            publisher.publish("RB2/ROBO2", "RB2XI1JAIPUR")
                        if ("Hyderabad" in str(city)):
                            print("Hyderabad")
                            city = "HYDER"
                            publisher.publish("RB2/ROBO2", "RB2XI1HYDER")
                    else:
                        print("Invalid station")

        cv2.imshow('INDUCT 1', frame0)
        cv2.waitKey(1)

    if (ret1):#for induct 2
        # Display the resulting frame
        # cv2.imshow('Cam 0', frame0)
        # Display the resulting frame
        Dist = []
        # Display the resulting frame
        frame1 = imutils.resize(frame1, width=800)
        corners, ids, rejected = cv2.aruco.detectMarkers(frame1, arucoDict, parameters=arucoParams)
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
                cv2.line(frame1, topLeftPoint, topRightPoint, (0, 255, 0), 2)
                cv2.line(frame1, topRightPoint, bottomRightPoint, (0, 255, 0), 2)
                cv2.line(frame1, bottomRightPoint, bottomLeftPoint, (0, 255, 0), 2)
                cv2.line(frame1, bottomLeftPoint, topLeftPoint, (0, 255, 0), 2)
                cX = int((topLeft[0] + bottomRight[0]) // 2)
                cY = int((topLeft[1] + bottomRight[1]) // 2)

                measure = abs(3.5 / (topLeft[0] - cX))
                cv2.circle(frame1, (cX, cY), 4, (255, 0, 0), -1)
                cv2.putText(frame1, str(
                    int(markerId)), (int(topLeft[0] - 10), int(topLeft[1] - 10)), cv2.FONT_HERSHEY_COMPLEX, 1,
                            (0, 0, 255))
                Dist.append((cX, cY))
            if (markerId == 2):
                for barcode in decode(frame1):
                    # print(barcode.data)
                    # print(barcode.rect)
                    myData = barcode.data.decode('utf-8')
                    print(myData)
                    pts = np.array([barcode.polygon], np.int32)
                    pts = pts.reshape((-1, 1, 2))
                    cv2.polylines(frame1, [pts], True, (255, 0, 255), 5)
                    pts2 = barcode.rect
                    cv2.putText(frame1, myData, (pts2[0], pts2[1]), cv2.FONT_HERSHEY_SIMPLEX, 0.9, (255, 0, 255), 2)

                    print(df[df['Shipment'] == myData])
                    comparison_values = df.values == myData
                    rows, cols = np.where(comparison_values == True)
                    city = df['Destination'][rows]
                    station1 = df['Induct Station'][rows]
                    station = str(station1)
                    print(station1)

                    if ("2.0" in station):
                        if ("Ahmedabad" in str(city)):
                            print("Ahmedabad")
                            city = "ABAD"
                            publisher.publish("RB1/ROBO1", "RB1XI2ABAD")
                        if ("Pune" in str(city)):
                            print("Pune")
                            city = "PUNE"
                            publisher.publish("RB1/ROBO1", "RB1XI2PUNE")
                        if ("Mumbai" in str(city)):
                            print("Mumbai")
                            city = "MUMBAI"
                            publisher.publish("RB1/ROBO1", "RB1XI2MUMBAI")
                        if ("Delhi" in str(city)):
                            print("Delhi")
                            city = "DELHI"
                            publisher.publish("RB1/ROBO1", "RB1XI2DELHI")
                        if ("Kolkata" in str(city)):
                            print("Kolkata")
                            city = "KOLKATA"
                            publisher.publish("RB1/ROBO1", "RB1XI2KOLKATA")
                        if ("Chennai" in str(city)):
                            print("Chennai")
                            city = "CHENNAI"
                            publisher.publish("RB1/ROBO1", "RB1XI2CHENNAI")
                        if ("Bengaluru" in str(city)):
                            print("Bengaluru")
                            city = "BENG"
                            publisher.publish("RB1/ROBO1", "RB1XI2BENG")
                        if ("Jaipur" in str(city)):
                            print("Jaipur")
                            city = "JAIPUR"
                            publisher.publish("RB1/ROBO1", "RB1XI2JAIPUR")
                        if ("Hyderabad" in str(city)):
                            print("Hyderabad")
                            city = "HYDER"
                            publisher.publish("RB1/ROBO1", "RB1XI2HYDER")
                    else:
                        print("Invalid station")

            if (markerId == 3):
                for barcode in decode(frame1):
                    # print(barcode.data)
                    # print(barcode.rect)
                    myData = barcode.data.decode('utf-8')
                    print(myData)
                    pts = np.array([barcode.polygon], np.int32)
                    pts = pts.reshape((-1, 1, 2))
                    cv2.polylines(frame1, [pts], True, (255, 0, 255), 5)
                    pts2 = barcode.rect
                    cv2.putText(frame1, myData, (pts2[0], pts2[1]), cv2.FONT_HERSHEY_SIMPLEX, 0.9, (255, 0, 255), 2)

                    print(df[df['Shipment'] == myData])
                    comparison_values = df.values == myData
                    rows, cols = np.where(comparison_values == True)
                    city = df['Destination'][rows]
                    station1 = df['Induct Station'][rows]
                    station = str(station1)
                    print(station1)

                    if ("2.0" in station):
                        if ("Ahmedabad" in str(city)):
                            print("Ahmedabad")
                            city = "ABAD"
                            publisher.publish("RB2/ROBO2", "RB2XI2ABAD")
                        if ("Pune" in str(city)):
                            print("Pune")
                            city = "PUNE"
                            publisher.publish("RB2/ROBO2", "RB2XI2PUNE")
                        if ("Mumbai" in str(city)):
                            print("Mumbai")
                            city = "MUMBAI"
                            publisher.publish("RB2/ROBO2", "RB2XI2MUMBAI")
                        if ("Delhi" in str(city)):
                            print("Delhi")
                            city = "DELHI"
                            publisher.publish("RB2/ROBO2", "RB2XI2DELHI")
                        if ("Kolkata" in str(city)):
                            print("Kolkata")
                            city = "KOLKATA"
                            publisher.publish("RB2/ROBO2", "RB2XI2KOLKATA")
                        if ("Chennai" in str(city)):
                            print("Chennai")
                            city = "CHENNAI"
                            publisher.publish("RB2/ROBO2", "RB2XI2CHENNAI")
                        if ("Bengaluru" in str(city)):
                            print("Bengaluru")
                            city = "BENG"
                            publisher.publish("RB2/ROBO2", "RB2XI2BENG")
                        if ("Jaipur" in str(city)):
                            print("Jaipur")
                            city = "JAIPUR"
                            publisher.publish("RB2/ROBO2", "RB2XI2JAIPUR")
                        if ("Hyderabad" in str(city)):
                            print("Hyderabad")
                            city = "HYDER"
                            publisher.publish("RB2/ROBO2", "RB2XI2HYDER")
                    else:
                        print("Invalid station")


        cv2.imshow('INDUCT 2 ', frame1)
        cv2.waitKey(1)

    if (ret2):#for arena cam 1

        Dist = []
        markerId_array = []
        # publisher.loop_start()
        image = imutils.resize(image, width=800)
        corners, ids, rejected = cv2.aruco.detectMarkers(image, arucoDict, parameters=arucoParams)
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
                cv2.line(image, topLeftPoint, topRightPoint, (0, 255, 0), 2)
                cv2.line(image, topRightPoint, bottomRightPoint, (0, 255, 0), 2)
                cv2.line(image, bottomRightPoint, bottomLeftPoint, (0, 255, 0), 2)
                cv2.line(image, bottomLeftPoint, topLeftPoint, (0, 255, 0), 2)
                cX = int((topLeft[0] + bottomRight[0]) // 2)
                cY = int((topLeft[1] + bottomRight[1]) // 2)

                measure = abs(3.5 / (topLeft[0] - cX))
                cv2.circle(image, (cX, cY), 4, (255, 0, 0), -1)
                cv2.putText(image, str(
                    int(markerId)), (int(topLeft[0] - 10), int(topLeft[1] - 10)), cv2.FONT_HERSHEY_COMPLEX, 1,
                            (0, 0, 255))
                Dist.append((cX, cY))
                markerId_array.append(markerId)
                aruco_centroid = (cX, cY)

            # static coordinate aruco
            if 2 in markerId_array:
                ind_2 = markerId_array.index(2)
                cx2, cy2 = Dist[ind_2]
            # print("CX2,CY2:   ", cx2, cy2)

            if 3 in markerId_array:
                ind_3 = markerId_array.index(3)
                cx3, cy3 = Dist[ind_3]
            # print("CX3,CY3:   ", cx3, cy3)

            if 4 in markerId_array:
                ind_4 = markerId_array.index(4)
                cx4, cy4 = Dist[ind_4]
            # print("CX4,CY4:   ", cx4, cy4)

            if 5 in markerId_array:
                ind_5 = markerId_array.index(5)
                cx5, cy5 = Dist[ind_5]
            # print("CX5,CY5:   ", cx5, cy5)

            if 6 in markerId_array:
                ind_6 = markerId_array.index(6)
                cx6, cy6 = Dist[ind_6]
            # print("CX6,CY6:   ", cx6, cy6)

            if 7 in markerId_array:
                ind_7 = markerId_array.index(7)
                cx7, cy7 = Dist[ind_7]
            # print("CX7,CY7:   ", cx7, cy7)

            if 8 in markerId_array:
                ind_8 = markerId_array.index(8)
                cx8, cy8 = Dist[ind_8]
            # print("CX8,CY8:   ", cx8, cy8)

            if 9 in markerId_array:
                ind_9 = markerId_array.index(9)
                cx9, cy9 = Dist[ind_9]
            # print("CX9,CY9:   ", cx9, cy9)

            if 10 in markerId_array:
                ind_10 = markerId_array.index(11)
                cx10, cy10 = Dist[ind_10]
            # print("CX10,CY10:   ", cx10, cy10)

            if 11 in markerId_array:
                ind_11 = markerId_array.index(11)
                cx11, cy11 = Dist[ind_11]
            # print("CX11,CY11:   ", cx11, cy11)

            dist_4_2 = abs((((cx2 - cx4) ** 2) - ((cy2 - cy4) ** 2)) ** 0.5)
            dist_4_2 = dist_4_2 * measure
            # print("Dist 4_2:", dist_4_2)

            dist_4_3 = abs((((cx3 - cx4) ** 2) - ((cy3 - cy4) ** 2)) ** 0.5)
            dist_4_3 = dist_4_3 * measure
            # print("Dist 4_3:", dist_4_3)

            dist_5_2 = abs((((cx2 - cx5) ** 2) - ((cy2 - cy5) ** 2)) ** 0.5)
            dist_5_2 = dist_5_2 * measure
            # print("Dist 5_2:", dist_5_2)

            dist_5_3 = abs((((cx3 - cx5) ** 2) - ((cy3 - cy5) ** 2)) ** 0.5)
            dist_5_3 = dist_5_3 * measure
            # print("Dist 5_3:", dist_5_3)

            dist_6_2 = abs((((cx2 - cx6) ** 2) - ((cy2 - cy6) ** 2)) ** 0.5)
            dist_6_2 = dist_6_2 * measure
            # print("Dist 6_2:", dist_6_2)

            dist_6_3 = abs((((cx3 - cx6) ** 2) - ((cy3 - cy6) ** 2)) ** 0.5)
            dist_6_3 = dist_6_3 * measure
            # print("Dist 6_3:", dist_6_3)

            dist_7_2 = abs((((cx2 - cx7) ** 2) - ((cy2 - cy7) ** 2)) ** 0.5)
            dist_7_2 = dist_7_2 * measure
            # print("Dist 6_2:", dist_6_2)

            dist_7_3 = abs((((cx3 - cx7) ** 2) - ((cy3 - cy7) ** 2)) ** 0.5)
            dist_7_3 = dist_7_3 * measure
            # print("Dist 7_3:", dist_7_3)

            dist_8_2 = abs((((cx2 - cx8) ** 2) - ((cy2 - cy8) ** 2)) ** 0.5)
            dist_8_2 = dist_8_2 * measure
            # print("Dist 8_2:", dist_8_2)

            dist_8_3 = abs((((cx3 - cx8) ** 2) - ((cy3 - cy8) ** 2)) ** 0.5)
            dist_8_3 = dist_8_3 * measure
            # print("Dist 8_3:", dist_8_3)

            dist_9_2 = abs((((cx2 - cx9) ** 2) - ((cy2 - cy9) ** 2)) ** 0.5)
            dist_9_2 = dist_9_2 * measure
            # print("Dist 9_2:", dist_9_2)

            dist_9_3 = abs((((cx3 - cx9) ** 2) - ((cy3 - cy9) ** 2)) ** 0.5)
            dist_9_3 = dist_9_3 * measure
            # print("Dist 9_3:", dist_9_3)

            dist_10_3 = abs((((cx3 - cx10 ** 2) - ((cy3 - cy10) ** 2)) ** 0.5))
            dist_10_3 = dist_10_3 * measure
            # print("Dist 10_3:", dist_10_3)

            dist_10_2 = abs((((cx2 - cx10) ** 2) - ((cy2 - cy10) ** 2)) ** 0.5)
            dist_10_2 = dist_10_2 * measure
            # print("Dist 10_2:", dist_10_2)

            dist_11_3 = abs((((cx3 - cx11) ** 2) - ((cy3 - cy11) ** 2)) ** 0.5)
            dist_11_3 = dist_11_3 * measure
            # print("Dist 11_3:", dist_11_3)

            dist_11_2 = abs((((cx2 - cx11) ** 2) - ((cy2 - cy11) ** 2)) ** 0.5)
            dist_11_2 = dist_11_2 * measure
            # print("Dist 11_2:", dist_11_2)

            # INDUCT 1
            # if ((dist_4_2 < 15) and (dist_4_3 < 15)):
            #     print("Collision_4")
            #     publisher.publish("RB2/ROBO2", "RB2XSTOP")
            #
            # if ((dist_5_2 < 15) and (dist_5_3 < 15)):
            #     print("Collision_5")
            #     publisher.publish("RB2/ROBO2", "RB2XSTOP")
            #
            # if ((dist_6_2 < 15) and (dist_6_3 < 15)):
            #     print("Collision_6")
            #     publisher.publish("RB2/ROBO2", "RB2XSTOP")
            #
            # if ((dist_7_2 < 15) and (dist_7_3 < 15)):
            #     print("Collision_7")
            #     publisher.publish("RB2/ROBO2", "RB2XSTOP")
            #
            # if ((dist_8_2 < 15) and (dist_8_3 < 15)):
            #     print("Collision_8")
            #     publisher.publish("RB2/ROBO2", "RB2XSTOP")
            #
            # if ((dist_9_2 < 15) and (dist_9_3 < 15)):
            #     print("Collision_9")
            #     publisher.publish("RB2/ROBO2", "RB2XSTOP")
            #
            # if ((dist_10_2 < 15) and (dist_10_3 < 15)):
            #     print("Collision_10")
            #     publisher.publish("RB2/ROBO2", "RB2XSTOP")
            #
            # if ((dist_11_2 < 15) and (dist_11_3 < 15)):
            #     print("Collision_11")
            #     publisher.publish("RB2/ROBO2", "RB2XSTOP")

        # DROPPING CENTROIDS
        # cv2.putText(image, 'DROP', (185, 43), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 150), 2)
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
                cv2.putText(image, str(centroid), (cx - 2, cy - 5), cv2.FONT_HERSHEY_SIMPLEX, 0.15, (255, 255, 255))
            # INDUCT 1

            if (markerId == 2):
                if (city == "ABAD") and (cx2 < 177 and cy2 < 133) and (cx2 > 174 and cy2 > 158):
                    print("stop")
                    # publisher.publish("RB3/ROBO3", "RB3XFWOFF")

                    # if (cx2 < 590 and cy2 < 70) and (cx2 > 500 and cy2 > 30):
                    print("Start_Servo_Abad")
                    publisher.publish("RB2/ROBO2", "RB2XSTOPSERVOABADI1")
                    cv2.putText(image, 'DROP', cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 150), 2)
                if (city == "PUNE") and (cx2 < 417 and cy2 < 88) and (cx2 > 407 and cy2 > 78):
                    print("stop")

                    print("Start_Servo_Pune")
                    publisher.publish("RB2/ROBO2", "RB2XSTOPSERVOPUNEI1")
                    cv2.putText(image, 'DROP', cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 150), 2)
                    # print("Stop_Servo_Pune")
                    # publisher.publish("RB2/ROBO2", "RB2XSTOPSERVOPUNEI1")

                    # if (cx2 < 590 and cy2 < 70) and (cx2 > 500 and cy2 > 30):
                if (city == "MUMBAI") and (cx2 < 177 and cy2 < 133) and (cx2 > 174 and cy2 > 158):
                    print("stop")

                    print("Start_Servo_Mumbai")
                    publisher.publish("RB2/ROBO2", "RB2XSTOPSERVOMUMBAII1")
                    cv2.putText(image, 'DROP', cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 150), 2)
                    # print("Stop_Servo_Mumbai")
                    # publisher.publish("RB2/ROBO2", "RB2XSTOPSERVOMUMBAII1")

                    # print("Stop_Servo_Mumbai")
                    # publisher.publish("RB2/ROBO2", "RB2XSTOPSERVOMUMBAII1")

                    # if (cx2 < 590 and cy2 < 70) and (cx2 > 500 and cy2 > 30):
                if (city == "DELHI ") and (cx2 < 178 and cy2 < 135) and (cx2 > 176 and cy2 > 130):
                    print("stop")

                    print("Start_Servo_Delhi")
                    publisher.publish("RB2/ROBO2", "RB2XSTOPSERVODELHII1")
                    cv2.putText(image, 'DROP',(cx2-2,cy2-5) ,cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 150), 2)
                    # print("Stop_Servo_Delhi")
                    # publisher.publish("RB2/ROBO2", "RB2XSTOPSERVOPUNEI1")
                    # print("Stop_Servo_Delhi")
                    # publisher.publish("RB2/ROBO2", "RB2XSTOPSERVODELHII1")

                    # if (cx2 < 590 and cy2 < 70) and (cx2 > 500 and cy2 > 30):
                if (city == "KOLKATA") and (cx2 < 178 and cy2 < 135) and (cx2 > 176 and cy2 > 130):
                    print("stop")

                    print("Start_Servo_Kolkata")
                    publisher.publish("RB2/ROBO2", "RB2XSTOPSERVOKOLKATAI1")
                    cv2.putText(image, 'DROP',(cx2-2,cy2-5) , cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 150), 2)
                    # print("Stop_Servo_Kolkata")
                    # publisher.publish("RB2/ROBO2", "RB2XSTOPSERVOKOLKATAI1")

                    #            if (cx2 < 590 and cy2 < 70) and (cx2 > 500 and cy2 > 30):
                if (city == "CHENNAI") and (cx2 < 178 and cy2 < 135) and (cx2 > 176 and cy2 > 130):
                    print("stop")

                    print("Start_Servo_Chennai")
                    publisher.publish("RB2/ROBO2", "RB2XSTOPSERVOCHENNAII1")
                    cv2.putText(image, 'DROP',(cx2-2,cy2-5) , cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 150), 2)
                    # print("Stop_Servo_Chennai")
                    # publisher.publish("RB2/ROBO2", "RB2XSTOPSERVOCHENNAII1")

                    # if (cx2 < 590 and cy2 < 70) and (cx2 > 500 and cy2 > 30):
                if (city == "HYDERABABAD ") and (cx2 < 178 and cy2 < 135) and (cx2 > 176 and cy2 > 130):
                    print("stop")

                    print("Start_Servo_HYDER")
                    publisher.publish("RB2/ROBO2", "RB2XSTOPSERVOHYDERI1")
                    cv2.putText(image, 'DROP',(cx2-2,cy2-5) , cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 150), 2)

                    # print("Stop_Servo_Hyder")
                    # publisher.publish("RB2/ROBO2", "RB2XSTOPSERVOHYDERI1")

                    # if (cx2 < 590 and cy2 < 70) and (cx2 > 500 and cy2 > 30):
                if (city == "BENG") and (cx2 < 178 and cy2 < 135) and (cx2 > 176 and cy2 > 130):
                    print("stop")

                    print("Start_Servo_Beng")
                    publisher.publish("RB2/ROBO2", "RB2XSTOPSERVOBENGI1")
                    cv2.putText(image, 'DROP',(cx2-2,cy2-5) , cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 150), 2)
                    # print("Stop_Servo_Beng")
                    # publisher.publish("RB2/ROBO2", "RB2XSTOPSERVOBENGI1")

                    # if (cx2 < 590 and cy2 < 70) and (cx2 > 500 and cy2 > 30):
                if (city == "JAIPUR") and (cx2 < 185 and cy2 < 50) and (cx2 > 178 and cy2 > 37):
                    print("stop")

                    print("Start_Servo_Jaipur")
                    publisher.publish("RB2/ROBO2", "RB2XSTOPSERVOJAIPURI1")
                    cv2.putText(image, 'DROP', (cx2 - 2, cy2 - 5), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 150), 2)

                # if (cx2 < 590 and cy2 < 70) and (cx2 > 500 and cy2 > 30):
                #     print("Stop_Servo_Abad")
                #     publisher.publish("RB2/ROBO2", "RB2XSTOPSERVOABADI1")
                #
                # if (cx2 < 590 and cy2 < 70) and (cx2 > 500 and cy2 > 30):
                #     print("Stop_Servo_Pune")
                #     publisher.publish("RB2/ROBO2", "RB2XSTOPSERVOPUNEI1")
                #
                # if (cx2 < 590 and cy2 < 70) and (cx2 > 500 and cy2 > 30):
                #     print("Stop_Servo_Mumbai")
                #     publisher.publish("RB2/ROBO2", "RB2XSTOPSERVOMUMBAII1")
                #
                # if (cx2 < 590 and cy2 < 70) and (cx2 > 500 and cy2 > 30):
                #     print("Stop_Servo_Delhi")
                #     publisher.publish("RB2/ROBO2", "RB2XSTOPSERVODELHII1")
                #
                # if (cx2 < 590 and cy2 < 70) and (cx2 > 500 and cy2 > 30):
                #     print("Stop_Servo_Kolkata")
                #     publisher.publish("RB2/ROBO2", "RB2XSTOPSERVOKOLKATAI1")
                #
                # if (cx2 < 590 and cy2 < 70) and (cx2 > 500 and cy2 > 30):
                #     print("Stop_Servo_Chennai")
                #     publisher.publish("RB2/ROBO2", "RB2XSTOPSERVOCHENNAII1")
                #
                # if (cx2 < 590 and cy2 < 70) and (cx2 > 500 and cy2 > 30):
                #     print("Stop_Servo_Hyder")
                #     publisher.publish("RB2/ROBO2", "RB2XSTOPSERVOHYDERI1")
                #
                # if (cx2 < 590 and cy2 < 70) and (cx2 > 500 and cy2 > 30):
                #     print("Stop_Servo_Beng")
                #     publisher.publish("RB2/ROBO2", "RB2XSTOPSERVOBENGI1")
                #
                # if (cx2 < 590 and cy2 < 70) and (cx2 > 500 and cy2 > 30):
                #     print("Stop_Servo_Jaipur")
                #     publisher.publish("RB2/ROBO2", "RB2XSTOPSERVOJAIPURI1")

            # INDUCT 2
            if (markerId == 3):
                if (cx3 < 590 and cy3 < 70) and (cx3 > 500 and cy3 > 30):
                    print("Stop_Servo_Abad")
                    publisher.publish("RB2/ROBO2", "RB2XSTOPSERVOABADI2")

                if (cx3 < 590 and cy3 < 70) and (cx3 > 500 and cy3 > 30):
                    print("Stop_Servo_Pune")
                    publisher.publish("RB2/ROBO2", "RB2XSTOPSERVOPUNEI2")

                if (cx3 < 590 and cy3 < 70) and (cx3 > 500 and cy3 > 30):
                    print("Stop_Servo_Mumbai")
                    publisher.publish("RB2/ROBO2", "RB2XSTOPSERVOMUMBAII2")

                if (cx3 < 590 and cy3 < 70) and (cx3 > 500 and cy3 > 30):
                    print("Stop_Servo_Delhi")
                    publisher.publish("RB2/ROBO2", "RB2XSTOPSERVODELHII2")

                if (cx3 < 590 and cy3 < 70) and (cx3 > 500 and cy3 > 30):
                    print("Stop_Servo_Kolkata")
                    publisher.publish("RB2/ROBO2", "RB2XSTOPSERVOKOLKATAI2")

                if (cx3 < 590 and cy3 < 70) and (cx3 > 500 and cy3 > 30):
                    print("Stop_Servo_Chennai")
                    publisher.publish("RB2/ROBO2", "RB2XSTOPSERVOCHENNAII2")

                if (cx3 < 590 and cy3 < 70) and (cx3 > 500 and cy3 > 30):
                    print("Stop_Servo_Hyder")
                    publisher.publish("RB2/ROBO2", "RB2XSTOPSERVOHYDERI2")

                if (cx3 < 590 and cy3 < 70) and (cx3 > 500 and cy3 > 30):
                    print("Stop_Servo_Beng")
                    publisher.publish("RB2/ROBO2", "RB2XSTOPSERVOBENGI2")

                if (cx3 < 590 and cy3 < 70) and (cx3 > 500 and cy3 > 30):
                    print("Stop_Servo_Jaipur")
                    publisher.publish("RB2/ROBO2", "RB2XSTOPSERVOJAIPURI2")

        cv2.imshow('ARENA CAM 1', image)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        cv2.destroyAllWindows()
        break

# When everything is done, release the capture
cap.release()
cap1.release()
cap2.release()


cv2.destroyAllWindows()
publisher.loop_stop()