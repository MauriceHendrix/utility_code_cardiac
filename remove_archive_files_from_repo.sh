git filter-branch --prune-empty -d /dev/shm/scratch  --index-filter "git rm --cached -f --ignore-unmatch data/archive/*.csv" --tag-name-filter cat -- --all
git reflog expire --expire=now --all
git gc --prune=now --aggressive 
git push -f
