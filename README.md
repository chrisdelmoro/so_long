<div id="top"></div>

<!-- PROJECT SHIELDS -->
<br/>
<p align="center">
    <img src="https://github.com/chrisdelmoro/so_long/blob/main/resources/repo/so_longm.png" alt="Logo" width="150" height="150">

  <p align="center">
    A simple 2D game. The short introduction to game development and visual elements.
    <br/>
    <img src="https://img.shields.io/badge/Mandatory-OK-brightgreen"/>
    <img src="https://img.shields.io/badge/Bonus-OK-brightgreen"/>
    <img src="https://img.shields.io/badge/Final%20Score-117-blue"/>
  </p>
</p>


<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#about-the-project">About The Project</a></li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>


<!-- ABOUT THE PROJECT -->
## About The Project

[![so_long][product-screenshot]](https://github.com/chrisdelmoro/so_long/blob/main/resources/repo/game.gif)

This project is a very small 2D game. Its purpose is to make the student work with textures, sprites, and some other very basic gameplay elements.
The student has to develop a game that takes as map file as a parameter, validades it according to several prerequesites, and then render the map to allow the game to be played. The player then has to collect every collectable to be able to complete the game.

The map prerequesites are:
1. The map needs to have a .ber extension;
2. The map has to be a rectangle;
3. The map can contain only valid caracters:
	* 1 to represent a wall;
	* 0 to represent empty space, or a walkable area;
	* P to represent the player character;
	* C to represent a collectable;
	* E to represent an exit for the map;
	* And in case of the bonus, an additional character to represent an enemy patrol;
4. The map can contain only one player;
5. The map can contain only one exit;
6. The map needs at least one collectable;

The buttons that can be pressed on the game are:
* W, A, S and D are used to move the player character;
* ESC can be pressed to close the game. You can also click the X button on the top right of the screen;

<p align="right">(<a href="#top">back to top</a>)</p>


## Prerequisites

This project uses 42s MiniLibX to render the game. Therefore you need to have it installed on your Linux machine. The library can be found [here](https://github.com/42Paris/minilibx-linux).

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- USAGE EXAMPLES -->
## Usage

Clone the repo and make it. Run ```make``` to play the mandatory part of the project and ```make bonus``` to play the bonus part of the project with exemy patrols and the movement counter on the windows, instead of the terminal.

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- LICENSE -->
## License

Distributed under the [GNU General Public License version 3 (GPLv3)](https://www.gnu.org/licenses/gpl-3.0.html). 

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- CONTACT -->
## Contact

Christian C. Del Moro - christian.delmor@gmail.com

Project Link: [https://github.com/chrisdelmoro/so_long](https://github.com/chrisdelmoro/so_long)

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[product-screenshot]: https://github.com/chrisdelmoro/so_long/blob/main/resources/repo/game.gif
