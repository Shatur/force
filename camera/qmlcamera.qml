import QtQuick 2.0
import QtQuick.Controls 1.4
import QtMultimedia 5.6
import ImageProcessor 1.0

Item {
    id: item

    signal donePhoto(string path, int orientation);

    Rectangle
        {
            id: background
            anchors.fill: parent
            color: "black"
        }

//shows live preview from camera
    VideoOutput {
        id: viewfinder
        source: camera
        anchors.fill: parent
        focus : visible
        autoOrientation: true
    }

    //shows captured image
    Image {
        id: photoPreview
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        visible: true
    }

    Camera {
        id: camera
        //imageCapture.resolution: Qt.size(1366, 768)
        imageProcessing.whiteBalanceMode: CameraImageProcessing.WhiteBalanceFlash
        captureMode: Camera.CaptureStillImage

        //exposure {
        //    exposureCompensation: -1.0
        //    exposureMode: Camera.ExposurePortrait
        //}

        flash.mode: Camera.FlashOff

        exposure {
                    exposureMode: Camera.ExposureAuto
                 }

        focus {
                    focusMode: Camera.FocusContinuous
                    focusPointMode: Camera.FocusPointCenter
              }

        imageCapture {
            resolution: Qt.size(1280, 1024)
            onImageCaptured: {
                photoPreview.source = preview
                console.log(preview)
                photoPreview.visible = true
                //photoPreview.rotation = camera.orientation
                //imageProcessor.processImage(preview);
                viewfinder.visible = false
            }
            onImageSaved:{
                console.log(path)
                item.donePhoto(path, camera.orientation)
            }
        }


    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            camera.imageCapture.capture();
        }
        /*Keys.volumeDownPressed: {imageCapture.capture();  visible= false;}
        Keys.volumeUpPressed: {imageCapture.capture();  visible= false;}*/
    }

    Button {
                id: shotBtn
                anchors { horizontalCenter: parent.horizontalCenter; bottom: parent.bottom }
                //text: "Зняти"
                //onClicked: console.log("This doesn't do anything yet...")
                iconSource: "qrc:/pics/camera-shot.png"
                onClicked: {camera.imageCapture.capture();  visible= false;}
               }

    Button {
            id: flashlight
            anchors { right: parent.right; bottom: parent.bottom }
            state: 'no_flashlight'

            iconSource: "qrc:/pics/flash-off.png"
            states: [
                    State {
                        name: "no_flashlight"
                        PropertyChanges {target: flashlight; iconSource: "qrc:/pics/flash-off.png" }
                    },
                    State {
                        name: "flashlight_on"
                        PropertyChanges {target: flashlight; iconSource: "qrc:/pics/flash.png" }
                    },
                    State {
                        name: "flashlight_auto"
                        PropertyChanges {target: flashlight; iconSource: "qrc:/pics/flash-auto.png" }
                    }
            ]

            onClicked: {
                if (state == 'no_flashlight') {state = 'flashlight_on'; camera.flash.mode = Camera.FlashOn}
                else if (state == 'flashlight_on') {state = 'flashlight_auto'; camera.flash.mode = Camera.FlashAuto}
                else if (state == 'flashlight_auto') {state = 'no_flashlight'; camera.flash.mode = Camera.FlashOff}
            }
    }


    function camShow()
    {
        console.log("camShow called ");
        console.log( JSON.stringify(camera.supportedViewfinderResolutions(1)))
        console.log(camera.imageCapture.resolution)
        camera.captureMode = Camera.CaptureStillImage;
        camera.start();
        photoPreview.visible = false
        viewfinder.source = camera
        viewfinder.visible = true
        shotBtn.visible = true
    }

    function camHide()
    {
        console.log("camHide called ");
        camera.stop();
        photoPreview.visible = false
    }


    //image processor for further image processing
    ImageProcessor{
        id: imageProcessor
    }
}
