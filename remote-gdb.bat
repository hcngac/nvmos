aws ec2 start-instances --instance-ids i-0d522ff99edb890ca
aws ec2 describe-instances --instance-ids i-0d522ff99edb890ca

bash -c "ssh ubuntu@nvmosdev.benbenng.net \"gdb -s ~/workspace/nvmos/project/debug.sym -ex 'target remote localhost:1234'\""