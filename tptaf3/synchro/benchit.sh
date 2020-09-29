PID=`ps -L -o lwp -C $1| tail -1 `


CUSER=`ps -C$1 -o user| tail -1`
echo $CUSER
if `test $CUSER=$USER`
then
while `kill -USR1 $PID`
do
i=3
while `test $i -gt 0 `
do
    i=`expr $i - 1` 
    `kill -USR1 $PID`
    sleep 1
done 
sleep 4
done
else echo "il existe uneautre execution du fichier $1, lancee par un autre utilisateur"
fi