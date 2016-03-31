# sed 's/Jon/Jonathan/' < emails
# sed -n /PA/p < emails
# sed 's/Karen .*/*** karen has retired****/' < emails
# sed -n 's/[0-9][0-9][0-9]-[0-9][0-9][0-9]-[0-9][0-9][0-9]/catttt/p' < emails
# cat emails | grep -o [0-9][0-9][0-9]-[0-9][0-9][0-9]-[0-9][0-9][0-9]
# sed -ne 's/[^[0-9][0-9][0-9]-[0-9][0-9][0-9]-[0-9][0-9][0-9]]/1/p' < emails
# sed '/NJ/a from new jersy' < emails 

# sed '/NJ/a insert text here' emails
# sed -i '1 i\anything' emails