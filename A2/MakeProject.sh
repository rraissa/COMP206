#!/bin/bash 

cd ~/

if [ "! -d "project"" ]; then
	mkdir -p "project"
fi

cd ./project/

if [ "! -d "cs206"" ]; then
	mkdir -p "cs206"
fi

cd ./cs206/

name=$1

if [[ ! -e "$name" ]]; then
	mkdir -p "$name"
        mkdir "$name"/archive
        mkdir "$name"/backup
        mkdir "$name"/docs
        mkdir "$name"/assets
        mkdir "$name"/database
        mkdir "$name"/source	
else
	echo "This project name has already been used"
	exit
fi

cd ./$name/source

cat > backup.sh <<EOF
 if [ -f *.h ] ; then
                cp *.h ./../backup
        fi

 if [ -f *.c ] ; then
                cp *.c ./../backup
        fi          
EOF

chmod 755 backup.sh

echo "Your project directories have been created"
  
