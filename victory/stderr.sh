#!/bin/bash
if stderr=$(command 2>&1 > /dev/null) && test -z "$stderr"; then echo "ok"; fi
