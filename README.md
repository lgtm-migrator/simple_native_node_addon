# simple_native_node_addon
My first native nodejs addon

what I did:

ubuntu machine
sudo apt install cmake nodejs npm libboost-all-dev

on folder
npm install node-addon-api
npm install bindings //not used
npm install cmake-js --save-dev

tip node_modules/cmake-js/bin/cmake-js -d <folderWithCmake> -O <folderToBuild>

command to build
mkdir build
cd build
cmake ..
../node_modules/cmake-js/bin/cmake-js -d ../addon/ -O ./addon


Run executable:
<path>/simple_native_node_addon/build/nodeExecuter
