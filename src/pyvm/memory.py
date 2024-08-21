class memory:
    _memlist = []
    def __init__(self, value=[]) -> None:
        self._memlist = value
    def __setitem__(self, key, value):
        if key >= len(self._memlist):
            for i in range(key-len(self._memlist)+1):
                self._memlist.append(None)
        self._memlist[key] = value
    def __getitem__(self, key):
        return(self._memlist[key])
    def __str__(self) -> str:
        return(self._memlist.__str__())
    def __repr__(self) -> str:
        return(self._memlist.__repr__())
