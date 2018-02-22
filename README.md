Little Plugin for testing the Rviz MovableText. 
You have in the sample texts folder a file with a couple paragraphs to copy paste to test cases with several lines.
The value for Vertical Aligment and Horizontal Alignment correspond to the values of the enum 
 
Vertical:  
 0: below  
 1: above  
 2: center  
Horizontal:    
 0: left   
 1: center  

The background represents the HalfSize of the AABB of the MovableText. Each time you change the text you should disable then reenable it for it to change size. 
Its alignment should be the same as the Movable Text and with the same rotation center. 

