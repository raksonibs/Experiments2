echo "Filing"
for file in *; do
  if [ -w $file ]; then

    echo $file
  fi
done

echo "Done"
