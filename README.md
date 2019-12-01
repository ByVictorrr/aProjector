# [aProjector](https://github.com/ByVictorrr/VanD/tree/master/aProjector) - autofocusing Projector [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://github.com/ByVictorrr/aProjector/blob/master/LICENSE.md)

* Allows you to move the projector an arbitrary distance and auto focuses the image produced 

* Supports most touch screen phones ..


This project is based on the laws of optics in physics and the thin lens equation and the magnification of the thin Lens:

![Thin Lens](https://github.com/ByVictorrr/aProjector/blob/master/images/CodeCogsEqn.gif)

![Magnification single](https://github.com/ByVictorrr/aProjector/blob/master/images/MagEqn.gif)


Coding and wiring done by [@VicDelaplaine](https://twitter.com/VicDelaplaine) || https://byvictorrr.github.io

Machining, CAD, and assembly done by [@dvnielwvng](https://twitter.com/dvnielwvng?lang=en) || https://danielwang.github.io


## aProjector 

![video](https://github.com/ByVictorrr/aProjector/blob/master/images/operation.gif)

![front
view](https://github.com/ByVictorrr/aProjector/blob/master/images/front_view.jpg)

![top
view](https://github.com/ByVictorrr/aProjector/blob/master/images/top_view.jpg)



* Above shows the mechanism that we will use to put the phone in a fixed place
so we know the location on startup.


## What are lenses?

A lens is a transparent piece of glass or plastic with at least one curved surface. It gets its name from the Latin word for "lentil" (a type of pulse used in cooking), but don't let that confuse you. There's no real reason for this other than that the most common kind of lens (called a convex lens) looks very much like a lentil!

## How do lenses work?

A lens works by refraction: it bends light rays as they pass through it so they change direction. (You can read a full explanation of why this happens in our article on light.) That means the rays seem to come from a point that's closer or further away from where they actually originate—and that's what makes objects seen through a lens seem either bigger or smaller than they really are.


## Types of lenses

There are two main types of lenses, known as convex (or converging) and concave (or diverging).

### Converging lenses

In a convex lens (sometimes called a positive lens), the glass (or plastic) surfaces bulge outwards in the center giving the classic lentil-like shape. A convex lens is also called a converging lens because it makes parallel light rays passing through it bend inward and meet (converge) at a spot just beyond the lens known as the focal point.

![imageOfConverging Lens](http://www.bbc.co.uk/staticarchive/756eb0a415fa7500e0035e75af0a9428fe0ffc84.jpg)

Convex lenses are used in things like telescopes and binoculars to bring distant light rays to a focus in your eyes.

### Diverging lenses

A concave lens is exactly the opposite with the outer surfaces curving inward, so it makes parallel light rays curve outward or diverge. That's why concave lenses are sometimes called diverging lenses. (One easy way to remember the difference between concave and convex lenses is to think of concave lenses caving inwards.)

![imageOfDiverging Lens](http://www.physics.usyd.edu.au/teach_res/hsp/sp/mod31/m31_diverging_files/image127.png)

Concave lenses are used in things like TV projectors to make light rays spread out into the distance. In a flashlight, it's easier to do this job with a mirror, which usually weighs much less than a lens and is cheaper to manufacture as well.

## Schematic:
![schematic](https://github.com/ByVictorrr/aProjector/blob/master/images/schematic.png)

## Hardware:

[MSP432p401R](https://www.amazon.com/Arduino-Pro-Mini-328-16MHz/dp/B004G53J5I)


[Phone](https://www.amazon.com/BLU-Advance-Unlocked-Smartphone-Black/dp/B072N6BD9V/ref=sr_1_1?s=electronics&ie=UTF8&qid=1531204782&sr=1-1&keywords=cheap+phone)

The device that provides the image to be projected.

[Stepper motor](https://www.amazon.com/Longruner-Stepper-Uln2003-arduino-LK67/dp/B015RQ97W8/ref=sr_1_4?s=electronics&ie=UTF8&qid=1531204743&sr=1-4&keywords=stepper+motor)

The stepper motor provides the force to translate the phone the optimal distance away from the lens 'd0' such that the image projected is clear. 'r' is the radius of the shaft of the stepper motor (2.5 mm).

[Ultra Sonic Sensor](https://www.amazon.com/Ultrasonic-Distance-Measuring-Compatible-Duemilanove/dp/B00SXZWMCS/ref=sr_1_6?s=electronics&ie=UTF8&qid=1531204694&sr=1-6&keywords=ultrasonic+sensor<Paste>)

This sensor determines the distance between the front end of aProjector and the wall.

[12V Battery](https://www.amazon.com/Energizer-Alkaline-General-Purpose-Battery/dp/B00003IE4E/ref=sr_1_4?s=electronics&ie=UTF8&qid=1531616254&sr=1-4&keywords=9V+Battery+with+DC)
 
This is the power source for our system.
 
[HC-05(control)](https://www.amazon.com/)

After each use, this button serves as a reset such that 'd0' can be reset to the starting value.

[Converging Lens (20cm FL; 10cm diameter)](https://www.amazon.com/Eisco-Piece-Premium-Optical-Diameter/dp/B00BIKGMZ8/ref=sr_1_2?ie=UTF8&qid=1531337023&sr=8-2&keywords=converging+lens)

The lens amplifies the display on the phone.


## Mechanisms:

[Lead Screw Set](https://www.amazon.com/BIQU-Copper-Coupler-Bearing-Printer/dp/B01H1QGGEE/ref=sr_1_3?ie=UTF8&qid=1532975365&sr=8-3&keywords=8mm+screw+rod#feature-bullets-btf)

This lead screw set contains a lead screw, copper nut, coupler, and pillow bearings. The coupler will attach to the stepper motor and the lead screw, allowing the lead screw to rotate. Then, the nut will translate the rotation into a horizontal translation. The bearings provide support.

[Linear Shaft Rail Rod (x2)](https://www.amazon.com/dp/B07G14C2BB/ref=sr_1_12?s=industrial&ie=UTF8&qid=1532984316&sr=1-12&keywords=Linear+Shaft+Rail+Rod+Bearing+Slide+Support+300+mm)

The two rail rods will be on either side of the lead screw and will serve as a linear actuating track for the phone holder to travel on. 


## Other Equipment Needed:

[Dark Acrylic Plates](https://www.interstateplastics.com/Acrylic-Bronze-2370-Extruded-Paper-masked-transparent-11-Sheet-ACRZ0EFSH.php?sku=ACRZ0EFSH&vid=20180730225032-4p&dim2=6&dim3=15&thickness=0.236&qty=2)

These acrylic plates will serve as the walls that enclose the mechanisms and hardware.

Phone Holder

We 3D-printed a device to hold standard-sized smartphones such that their screens would be parallel to and facing the convex lens. The holder attaches to the nut and slides along the two rail rods.

Lens Holder

This 3D-printed device holds the lens in place, allowing the image from the phone screen to be projected accurately through it.

## Software:

aProjector's source code and schematic can be obtained in entirety from my Github: https://github.com/ByVictorrr/aProjector


## Resources
You can learn about lenses and refraction from a few places, including:

* [Derivation for Thin Lense EQN.](http://www.physics.louisville.edu/cldavis/phys299/notes/lo_lenses.html)

* [The Anatomy of a Lens](http://www.physicsclassroom.com/class/refrn/Lesson-5/The-Anatomy-of-a-Lens)

* [What is a lens](https://www.explainthatstuff.com/lenses.html)

## Contact
Point of Contact: [email](vdelaplainess@gmail.com)


