#!/bin/sh

command=$1

# if [ `whoami` != "root" ]
#     then
#     echo 'Ban can phai chay lenh sudo de thay doi thoi gian'
#     exit $E_NOTROOT
# fi

if [ -z $command ]
    then echo "Chua nhap chuc nang"
fi

if [ $command = "info" ]
    then TZ="Asia/Ho_Chi_Minh" date
fi

if [ $command = "set-hour" ]
    then
        if [ `whoami` != "root" ]
            then
            echo 'Ban can phai chay lenh sudo de thay doi thoi gian'
            exit $E_NOTROOT
        fi
        echo "Xin hay nhap gio theo dinh dang hh:mm:ss?"
        read new_time
        date +%T -s $new_time
fi

if [ $command = "set-date" ]
    then
        if [ `whoami` != "root" ]
            then
            echo 'Ban can phai chay lenh sudo de thay doi thoi gian'
            exit $E_NOTROOT
        fi
        echo "Xin hay nhap ngay theo dinh dang yyyymmdd?"
        read new_time
        date +%Y%m%d -s $new_time
fi

if [ $command = "automatic" ]
    then
        if [ `whoami` != "root" ]
            then
            echo 'Ban can phai chay lenh sudo de thay doi thoi gian'
            exit $E_NOTROOT
        fi
        echo "Thoi gian dang duoc cap nhat theo server cua Microsoft..."
        ntpdate -4 time.windows.com
fi
