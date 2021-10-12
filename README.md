# simple_native_node_addon
My first native nodejs addon

what I did:

ubuntu machine
```shell
sudo apt install cmake nodejs npm libboost-all-dev
```

on repo:

```shell
npm install node-addon-api
npm install bindings //not used
npm install cmake-js --save-dev
```

tip: node_modules/cmake-js/bin/cmake-js -d <folderWithCmake> -O <folderToBuild>

command to build:

```shell
mkdir build
cd build
cmake ..
make
../node_modules/cmake-js/bin/cmake-js -d ../addon/ -O ./addon
```

Run executable:
```shell
<path>/simple_native_node_addon/build/nodeExecuter
```
