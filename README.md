# Campus-Navigator
Campus navigator is a Navigation system that can work even in the absence of GPS connectivity. The system will have a hand-held device that automatically locates the user location and updates it to the user. Based on the destination inputs given by the user, the system determines the shortest path to the desired destination of the user.

There will be navigators at some points inside the campus, but users do not have continuous help to get to their destination. They can try to figure out a way to get to their
target destination as per the navigators available in the campus. However when they start walking towards their target direction, they have no help anymore and face many
problems. The campus navigator will help in overcoming these problems and provide efficient path to the desired destination.

![image_2021-11-10_12-31-14](https://user-images.githubusercontent.com/69961625/141065472-b7787780-368e-4663-a5ad-ae4fd80ed3d4.png)

The system is mainly based on the transmission of the data between the RF transceiver modules. The encoder integrated circuit (IC) is coded with the data bits which has the
location information of the transmitting building or block. The IC generates series of bits which has both security bits and the data bits. These series of bits are continuously
transmitted by the RF transmitters placed at every block in the campus. The user has to carry the RF receiver module with him. When the RF receiver module comes in the range
of the transmitter signals, the code encoded in that signal is decoded by the decoder IC and sent to the Arduino board. The Arduino board processes the data bits received and
the user location which is decoded will be displayed over the LCD screen.The receiver module with the user then asks for the destination location information in the form of digits. Based on the current location and user input on the destination, the Arduino board estimates the shortest path to the destination. This information is displayed on the LCD screen.

![image_2021-11-10_12-36-05](https://user-images.githubusercontent.com/69961625/141065994-3853003e-2866-4b93-9fcb-a4038430349b.png)


Above Figure depicts the overall working of the system, Campus Navigator.It shows how a person who wants to navigate to other location inside the campus uses the module.
The person with the receiver module comes towards a block which is near to him and the receiver module decodes the signal from RF transmitter in the block and shows user's
current location inside the campus. In Fig, the user is near to the transmitter module-1. When he enters the destination input as block-3, the receiver module calculates theshortest path to block-3 from block-1 which is current location of the user and displays on the LCD screen.


![image_2021-11-10_12-37-37](https://user-images.githubusercontent.com/69961625/141066202-70a9120f-e3c7-4cc6-a84b-d41f005f5232.png)

The Campus Navigator system provides the current location of the user. It also gives the shortest path to the destination location by displaying path on the LCD panel. Above Fig gives the snapshot of the "Campus Navigator" circuit
