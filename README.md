# RISCV-LUT
This is a manual to install a RISCV simulator on your destop

### 1. Install docker on your desktop

- Install Docker on your systems

  For Linux or WSL, you need to enter the following command in the terminal
  
  ```sh
  sudo apt-get update
  sudo apt-get upgrade -y
  sudo apt install docker
  ```

  For Windows/Mac, click on this [link](https://docs.docker.com/desktop/setup/install/windows-install/)

- Build Dockerfile

  After installing the Docker, you need to clone this repo by entering this following command on you GitBash(Windows/mac) & Terminal(Linux & WSL)

    ```sh
    git clone https://github.com/ChaZamFr/Riscv-LUT.git
    ```

  Then enter go to the cloned file

  ```sh
  cd RISCV-LUT/
  ```

  Then you need to build the Dockerfile by running the following command
  
  ```sh
  docker build buildenv -t risc-buildenv
  ```

  Then run the Dockerfile

  ```sh
  #For Linux/WSL
  docker run -dit -v $(pwd):/root/env --name risc-container risc-buildenv

  #For Windows/Mac
  docker run --rm -it -v %cd%:/root/env risc-buildenv
  ```

  After running, execute the docker file

  ```sh
  docker exec -it risc-container bash
  ```

  DONE! You have successfully created your Docker Container!

-  Installation of Dependencies

    Now install all the dependencies one by one
  
    ```sh
    sudo apt-get update
    sudo apt-get upgrade -y
    sudo apt install python3
    sudo apt install python3-pip
    sudo apt install verilator
    sudo apt install vim #text-editor
    sudo apt install git
    ```

    Then you need to create your Virtual environment for you Python
 
    ```sh
    sudo apt install python3-venv
    python3 -m venv myenv #myenv is the name of the virtual environment, you can chamge the name
    source myenv/bin/activate
    ```

    DONE! You have even created your python's venv!
  


### 2. Loading ibex simulation on the Docker

  - To clone the ibex's from git, enter the following command on your docker's terminal
    
    ```sh
    git clone https://github.com/ChaZamFr/ibex.git
    ```

    You have cloned the git repo of ibex. But to run the simulation, we need a riscv-gcc compiler. For that we need to clone the following repo

    ```sh
    git clone https://github.com/riscv-collab/riscv-gnu-toolchain.git
    ```

    Install the pip dependencies "given in the repo." Then you need to add the path of the riscv-gnu toolchain in your bashrc file

    ```sh
    vim ~/.bashrc
    ```

    After entering into your bashrc file, add this line to your file

    ```sh
    export PATH=/opt/riscv/bin:$PATH
    ```

    After editing your bashrc file, you exit the editor and execute the change by entering the following command

    ```sh
    source ~/.bashrc
    ```

    Then run the following commands

    ```sh
    ./configure --prefix=/opt/riscv --with-arch=rv32gc --with-abi=ilp32d
    make linux 
    ```

    Then check whether the gcc compiler is installed by entering the following command

    ```sh
    riscv32-unknown-elf-gcc --version
    ```

### 3. Simulate ibex processor

- To simulate the ibex processor, change to ibex directory and follow the README file in the examples/simple_system directory. After installing the python requirements file, enter the following command to build the simulation of the ibex processor

  
    ```sh
    fusesoc --cores-root=. run --target=sim --setup --build \
        lowrisc:ibex:ibex_simple_system $(util/ibex_config.py opentitan fusesoc_opts)
    ```

- Then follow the steps of making and running the simulations in the examples/simple_system directory.
  

    
    

    


  
  
  
  
  
  
