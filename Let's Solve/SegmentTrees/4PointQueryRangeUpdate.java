// https://nados.io/question/what-s-at-idx-point-query-range-update?zen=true

import java.io.*;

class Main {

  public static class SegmentTree {

    int ar[];
    int lazy[];

    SegmentTree(int arr[]) {
      ar = arr;
      lazy = new int[ar.length * 4];
      build(1, 0, ar.length - 1);
    }

    private void build(int node, int start, int end) {
      if (start == end) {
        lazy[node] = ar[start];
      } else {
        int mid = (start + end) / 2;
        build(node * 2, start, mid);
        build(node * 2 + 1, mid + 1, end);
        lazy[node] = 0;
      }
    }

    void update(int l, int r, int val) {
      update(1, 0, ar.length - 1, l, r, val);
    }

    private void update(int node, int start, int end, int l, int r, int val) {

      if (l > end || r < start) {
        return;
      }
      if (start == end) {

        lazy[node] += val;
        ar[start] = lazy[node];
      } else if (start >= l && end <= r) {
        lazy[node] += val;
      } else {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, l, r, val);
        update(node * 2 + 1, mid + 1, end, l, r, val);
      }
    }

    int query(int ind) {
      return query(1, 0, ar.length - 1, ind);
    }

    private void propogate(int node) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
      lazy[node] = 0;
    }

    private int query(int node, int start, int end, int ind) {

      // System.out.println("Hello");
      if (start == end) {
        return lazy[node];
      } else {
        propogate(node);
        int mid = (start + end) / 2;
        if (ind <= mid) {
          return query(node * 2, start, mid, ind);
        } else {
          return query(node * 2 + 1, mid + 1, end, ind);
        }
      }
    }

  }

  public static void main(String[] args) throws Exception {
    BufferedReader read = new BufferedReader(new InputStreamReader(System.in));

    int n = Integer.parseInt(read.readLine());
    int arr[] = new int[n];

    for (int i = 0; i < n; i++) {
      arr[i] = Integer.parseInt(read.readLine());
    }

    SegmentTree obj = new SegmentTree(arr);

    int q = Integer.parseInt(read.readLine());

    StringBuilder out = new StringBuilder();
    while (q-- > 0) {
      String[] inp = read.readLine().split(" ");

      int t = Integer.parseInt(inp[0]);

      if (t == 0) {
        int ind = Integer.parseInt(inp[1]);
        long ans = obj.query(ind);
        out.append(ans + "\n");
      } else {
        int l = Integer.parseInt(inp[1]);
        int r = Integer.parseInt(inp[2]);
        int val = Integer.parseInt(inp[3]);
        obj.update(l, r, val);
      }
    }

    System.out.println(out);
  }

}