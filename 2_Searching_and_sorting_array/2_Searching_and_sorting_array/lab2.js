function arrsort1() {
    let a = document.getElementById("arr").value;
    const ar2 = a.split(" ");
    for (let j = 1; j < ar2.length; j++) {
        let key = ar2[j];
        let i = j - 1;
        while ((i > -1) && (ar2[i] > key)) {
            ar2[i + 1] = ar2[i];
            i--;
        }
        ar2[i + 1] = key;
    }
    let b2 = ar2.join(" ");
    document.getElementById("outp").value = b2;
    ar2.reverse();
    let b = ar2.join(" ");
    document.getElementById("outp4").value = b;
}
function arrsort2() {
    let a = document.getElementById("arr").value;
    const ar2 = a.split(" ");
    for (let i = 0; i < ar2.length - 1; i++) {
        for (let j = i + 1; j < ar2.length; j++) {
            if (ar2[i] > ar2[j]) {
                temp = ar2[i];
                ar2[i] = ar2[j];
                ar2[j] = temp;
            }
        }
    }
    let b2 = ar2.join(" ");
    document.getElementById("outp2").value = b2;
    ar2.reverse();
    let b = ar2.join(" ");
    document.getElementById("outp5").value = b;
}
function arrrev() {
    let a = document.getElementById("arr").value;
    const ar = a.split(" ");
    const ar2 = a.split(" ");
    let b2 = [];
    for (let i = ar2.length - 1; i >= 0; i--) {
        b2.push(ar2[i]);
    }
    let ans = b2.join(" ");
    document.getElementById("outp3").value = ans;
}
function sear(p) {
    let s = "-1";
    let a = document.getElementById("arr").value;
    const ar = a.split(" ");
    for (let i = 0; i < ar.length; i++) {
        if (ar[i] == p) {
            if (s == "-1") {
                s = "";
            }
            s += i.toString() + " ";
        }
    }
    document.getElementById("op").value = s;
    for (let i = 0; i < ar.length - 1; i++) {
        for (let j = i + 1; j < ar.length; j++) {
            if (ar[i] > ar[j]) {
                temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
    }
    let first = 0;
    let last = ar.length - 1;
    let mid;
    let key = p;
    if ((first + last) % 2 != 0) {
        mid = (first + last - 1) / 2;
    }
    else {
        mid = (first + last) / 2;
    }
    while (first <= last) {
        if (ar[mid] < key) {
            first = mid + 1;
        } else if (ar[mid] == key) {
            document.getElementById("op2").value = "Element is present";
            break;
        } else {
            last = mid - 1;
        }
        if ((first + last) % 2 != 0) {
            mid = (first + last - 1) / 2;
        }
        else {
            mid = (first + last) / 2;
        }
    }
    if (first > last) {
        document.getElementById("op2").value = "Element is not found!";
    }
}