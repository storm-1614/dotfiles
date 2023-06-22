sudo make modules_install
sudo cp arch/x86/boot/bzImage /boot/vmlinuz-linux-storm1614-cjktty
echo '完成'
sudo mkinitcpio -p linux-storm1614-cjktty
sudo grub-mkconfig -o /boot/grub/grub.cfg
