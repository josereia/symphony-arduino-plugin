<p align="center">:construction: Projeto em desenvolvimento !! :construction:</p>

<h2 align="center">
  <p><img width="200px" src="assets/logo.png"></p>
  symphony arduino
  <p></p>
</h2>

<p>
  <img src="https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white">
  <img src="https://img.shields.io/badge/-Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white">
  <p>
    <img src="https://img.shields.io/github/stars/josereia/symphony-arduino-plugin?color=yellow">
    <img src="https://img.shields.io/github/forks/josereia/symphony-arduino-plugin?color=important">
  </p>
</p>
  
## :scroll: Sobre
<p>Um programa para arduino que se conecta ao reprodutor de músicas <a href="https://github.com/josereia/symphony-desktop"><b>symphony-desktop</b></a> através da porta serial. O objetivo é sincronizar a cor de uma fita de led comum com a cor de destaque da capa do album que está tocando.</p>
<p>Para isso, foi utilizado a porta serial do arduino que recebe a cor de destaque rgb, compara com as cores pré-definidas da fita de led e emite o comando/código correto através da biblioteca IRemote para o led infravermelho que transmite esse comando para a controladora da fita de led.</p>
<p>No <a href="https://github.com/josereia/symphony-desktop"><b>symphony-desktop</b></a> foi usado um algoritimo de aproximação de cores para pegar a cor da fita de led mais próxima da cor de destaque do album, haja vista que as cores da fita de led comum são limitadas.</p>

## 🧰 Tecnologias usadas
>Até o momento.
- C++
- IRremote
- Arduino

## :computer: Plataformas suportadas
>Até o momento.
<p>
  <img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" />
  <img src="https://img.shields.io/badge/-Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white"/>
</p>

## 📷 Imagens do projeto
>Esquema do arduino
<p>Led infravermelho ligado ao pino 3.</p>
  <img src="assets/esquema.png"/>

>Preview
<p>Projeto rodando no Arduino Uno em conjunto ao reprodutor de músicas symphony-desktop.</p>
<img src="assets/preview.gif" />
  
