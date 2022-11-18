mkdir /home/kernelbuild2
cd /home/kernelbuild2
wget -P /home/kernelbuild2/ https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.19.17.tar.xz
unxz linux-5.19.17.tar.xz 
tar -xvf linux-5.19.17.tar
chown -R $USER:$USER linux-5.19.17
cd /home/kernelbuild2/linux-5.19.17
wget -P /home/kernelbuild2/linux-5.19.17 --no-check-certificate 'https://docs.google.com/uc?export=download&id=15wIy6KDTNTQ9zgok2mOErfGn8QsSvGZ3' -O .config
make -j2