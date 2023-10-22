#! /usr/bin/bash

if [[ -z "$1" ]]; then
  echo "Usage: $0 result_file_name"
  exit 1
fi

if command -v meld >/dev/null 2>&1; then
  meld $1 /tmp/miniob/result_output/$(basename $1).tmp  > /dev/null 2>&1 &
else
  diff $1 /tmp/miniob/result_output/$(basename $1).tmp  > /dev/null 2>&1 &
fi