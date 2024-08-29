<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a name="readme-top"></a>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->


<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/othneildrew/Best-README-Template">
    <img src="logo/Redfox_coding.jpg" alt="Logo" width="160" height="160">
  </a>

  <h3 align="center">cub3D</h3>



</div>


<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

The Cub3D project, introduces students to 3D rendering using raycasting techniques, 
inspired by classic first-person shooter games like Wolfenstein 3D. 

The goal is to create a simple 3D game engine that simulates a player’s movement in a 3D space while handling 
textures, walls, and perspective projection.

**Project Overview:**

- Raycasting: The project revolves around implementing raycasting to project a 3D view from a 2D map, calculating the distance between the player and objects to create the illusion of depth.
- Basic Movement: The player can move forward, backward, and rotate their view to explore the map.
- Map Parsing: The engine reads a map from a file, where walls, spaces, and other elements are defined.
- Textures and Colors: Apply textures to walls and floors/ceilings to enhance the graphical experience.

**Bonus Features:**

- Mini-Map: Implement an on-screen mini-map that displays the player’s position and surroundings in real time.
- Mouse Support: Integrate mouse control to allow more fluid player movement and viewing angles.

For this project the school give us a basic [graphic library](https://macrolibx.kbz8.me/guides/getting_started/).

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- GETTING STARTED -->
## Getting Started

### Prerequisites

This is a C program so you need to have gcc compiler.
  ```sh
  sudo apt-get install gcc -y
  ```
(!) To install the graphic library, please check the readme inside the MacroLibX folder.
### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/Lyyrst/cub3D.git
2. Makefile !
   ```sh
   make bonus && make clean
   ```
<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage

run the following command with a well formated map :
```sh
./cub3D [map]
```
Test our personal map :
```sh
./cub3D maps/nether.cub
```
<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- CONTACT -->
## Contact

[Discord : lyrst](https://discord.com/users/257192704537001984)

kurt.butorp@gmail.com

## Reminder

Please remember that this project is one of the first I did as a computer science learner, it does not reflect my actual skills but through which project I learned programming.
