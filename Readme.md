<h1 align="center">Irrigation System</h1>
<h6 align="center">ESP32 Websocket with React Frontend</h6>


<!-- 1. Bootstrapped with [Astro](https://astro.build/). -->

## 👾 Run Frontend project

1. Install the dependencies

  ```sh
  # /web
  cd web
  npm install
  ```

2. Start development server

  ```sh
  # /web
  npm run dev
  ```

2. Build for production

  ```sh
  # /web
  npm run build
  ```

## 👾 Build and Run for production ESP32

1. Build & Upload frontend web to esp32

  ```sh
  # You need to move the output from /web/dist folder inside /data folder, after that should be build the filesystem image with:

  pio run --target buildfs --environment upesy_wroom

  # then load the file system with:

  pio run --target uploadfs --environment upesy_wroom
  ```

2. Upload project to esp32

  ```sh
  pio run --target upload --upload-port <port>
  ```

### 🛠 Built with

- ESP32
- Arduino
- ESP Async WebServer
- React Typescript + SWC
- Shadcn/ui

### 💻 Author

- Portfolio - [@newtyf](https://newtyf.com)
- Instagram - [@newtyf](https://www.instagram.com/newt_yf/)
- LinkedIn - [@newtyf](https://www.linkedin.com/in/axel-mu%C3%B1oz/)
- Frontend Mentor - [@newtyf](https://www.frontendmentor.io/profile/TREz-bits)